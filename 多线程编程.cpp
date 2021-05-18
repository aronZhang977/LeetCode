/*
    子线程循环十次，主线程循环100次，再回到子线程循环10次，再回到主线程循环100次，如此循环50次。
*/
mutex m;      // 互斥锁
condition_variable cond;    //条件变量
int flag = 10;  // 条件

void fun(int num){
    for(int i = 0; i < 50; i++)
    {
        unique_lock<mutex> lk(m);
        while(flag != num)
            cond.wait(lk);  //调用wait时会执行lk.unlock()
        for(int j = 0; j < num; j++)
        {
            cout << j << " ";
        }
        cout << endl;
        flag = (num == 10)? 100 : 10;   // 被阻塞的线程唤醒后lk.lock()恢复在调用wait前的状态
        cond.notify_one(); 
    }
}

int main(){
    thread child(fun,10);
    fun(100);
    child.join();

    return 0;
}

/*
    开启3个线程，这3个线程的id分别为ABC，每个线程将自己的id在屏幕上打印10遍，要求输出结果按abc的顺序
*/
mutex m;
codition_cariable cond;
int loop = 10;
int flag = 0;

void func(int id)
{
    for(int i = 0; i < loop; ++i)
    {
        unique_lock<mutex> lk(m);
        while(flag != id)
            cond.wait(lk);
        cout << static_cast<char>('A'+id) <<" ";
        flag = (flag + 1) % 3;
        cond.notify_all();        
    }
}

void main()
{
    thread A(func, 0);
    thread B(func, 1);
    func(2);
    cout << endl;

    A.join();
    B.join();
}

/*
    有四个线程1/2/3/4.分别的功能就是输出对应数字，现在又四个文件，初始为空，现要让四个文件呈如下格式
    A：1.2.3.4.1.2...
    B：2.3.4.1.2.3...
    C：3.4.1.2.3.4...
    D：4.1.2.3.4.1...
*/

mutex m;
condition_variable cond;
int loop = 10;
int flag;

void func(int num)
{
    for(int i = 0; i < loop; ++i)
    {
        unque_lock<mutex> lk(m);
        while(num != flag)
            cond.wait(lk);
        cout << num + 1 << " ";
        flag = (flag + 1) % 4;
        cond.notify_all();
    }
}

void main(int argc, char* argv[])
{
    flag = atoi(argv[1]);
    thread one(func, 1);
    thread two(func, 2);
    thread three(func, 3);
    func(0);
    one.join();
    two.join();
    three.join();
    cout << endl;
}

/*
    读写者问题
*/
class relock{
private:
    mutex _lock;
    condition_variable _wcon,_rcon;
    unsigned _writer,_reader;
    int _ active;
public:
    rwlock()   
    :_writer(0),_reader(0),_active(0)
    {}

    void read_lock(){
        unque_lock<mutex> lock(_lock);
        ++_reader;
        while(_active < 0 || _writer > 0)
            _rcon.wait(lock);
        --_writer;
        _active = -1;
    }

    void write_lock(){
        unique_lock<mutex> lock(_lock);
        if(_active > 0)
        {
            --_active;
            if(_active == 0)
                _wcaon.notify_one();
        }
        else{
            _active = 0;
            if(_reader > 0)
                _rcon.notify_all();
        }
    }
};

void t1(rwlock* rwl)
{
    while (1)
    {
        cout << "I want to write." << endl;
        rwl->write_lock();
        cout << "writing..." << endl;
        this_thread::sleep_for(chrono::seconds(5));
        rwl->unlock();
        this_thread::sleep_for(chrono::seconds(5));
    }
    
}

void t2(rwlock* rwl)
{
    while(1)
    {
        cout << "t2-I want to read." << endl;
        rwl->read_lock();
        cout << "t2-reading..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        rwl->unlock();
    }
}

void t3(rwlpck* rwl)
{
    while(1)
    {
        cout << "t3-I want to read." << endl;
        rwl->read_lock();
        cout << "t3-reading..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        rwl->unlock();
    }
}

int main()
{
    rwlock* rwl = new rwlock();
    thread th1(t1,rwl);
    thread th2(t2,rwl);
    thread th3(t3,rwl);
    th1.join();
    th2.join();
    th3.join();

    return 0;
}


/*
    线程安全的queue
    stl中的queue是非线程安全的，实现一个线程安全的queue
*/
template<typename T>
class threadsafe_queue
{
private:
    mutable std::mutex mut;
    std::queue<T> data_queue;
    std::condition_variable data_cond;
public:
    threadsafe_queue() {}
    threadsafe_queue(threadsafe_queue const& other)
    {
        std::lock_guard<std::mutex> lk(other.mut);
        data_queue = other.data_queue;
    }
    void push(T new_value)//入队操作  
    {
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(new_value);
        data_cond.notify_one();
    }
    void wait_and_pop(T& value)//直到有元素可以删除为止  
    {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this] {return !data_queue.empty(); });
        value = data_queue.front();
        data_queue.pop();
    }
    std::shared_ptr<T> wait_and_pop()
    {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this] {return !data_queue.empty(); });
        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }
    bool try_pop(T& value)//不管有没有队首元素直接返回  
    {
        std::lock_guard<std::mutex> lk(mut);
        if (data_queue.empty())
            return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    std::shared_ptr<T> try_pop()
    {
        std::lock_guard<std::mutex> lk(mut);
        if (data_queue.empty())
            return std::shared_ptr<T>();
        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }
    bool empty() const
    {
        std::lock_guard<std::mutex> lk(mut);
        return data_queue.empty();
    }
};

/*
    题目：编写程序完成如下功能：

1）有一int型全局变量g_Flag初始值为0

2） 在主线称中起动线程1，打印“this is thread1”，并将g_Flag设置为1

3） 在主线称中启动线程2，打印“this is thread2”，并将g_Flag设置为2

4） 线程序1需要在线程2退出后才能退出

5） 主线程在检测到g_Flag从1变为2，或者从2变为1的时候退出
*/

atomic<int> flag(0);

void worker1(future<int> fut) 
{//线程1  
    printf("this is thread1\n");
    flag = 1;
    fut.get();//线程1阻塞至线程2设置共享状态  get等待异步操作结束并返回结果
    printf("thread1 exit\n");
}

void worker2(promise<int> prom) 
{//线程2  
    printf("this is thread2\n");//C++11的线程输出cout没有boost的好，还是会出现乱序，所以采用printf，有点不爽  
    flag = 2;
    prom.set_value(10);//线程2设置了共享状态后，线程1才会被唤醒  
    printf("thread2 exit\n");
}

//利用promise future来控制线程退出的次序
int main()
{
    promise<int> prom;
    future<int> fut = prom.get_future();
    thread one(worker1, move(fut));//注意future和promise不允许拷贝，但是具备move语义  
    thread two(worker2, move(prom));
    while (flag.load() == 0);　　///将本线程从调用线程中分离出来，允许本线程独立执行
    one.detach();
    two.detach();
    //exit(1);//主线程到这里退出  
    printf("main thread exit\n");

    system("pause");
    return 0;
}


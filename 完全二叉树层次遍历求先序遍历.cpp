#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

#define FUNC 0

using namespace std;

vector<string> getLevelOrder()
{
    vector<string> res;
    string strTmp;
    while(cin >> strTmp)
    {
        res.push_back(strTmp);
    }
    return res;
}

#if FUNC
// 非递归
vector<string> levelOrderToPreOrder(vector<string>& vLevelOrder)
{
    vector<string> res;
    stack<int> stk;
    int idx = 0;
    while(idx != -1 || !stk.empty())
    {
        if(-1 == idx)    
        {
            idx = stk.top();
            stk.pop();
        }

        res.push_back(vLevelOrder[idx]);

        if (2 * idx + 2 < vLevelOrder.size())
        {
            stk.push(2 * idx + 2);
        }
        if (2 * idx + 1 < (int)vLevelOrder.size())
        {
            idx = 2 * idx + 1;
        }
        else
        {
            idx = -1;
        }
    }
    return res;
}
#else
// 递归
void dfs(vector<string>& vLevelOrder,vector<string>& vPreOrder, int nRoot)
{
    //    前序 [根左右]
    vPreOrder.push_back(vLevelOrder[nRoot]);
    if(2 * nRoot + 1 < (int)vLevelOrder.size())
    {
        int nTmp = 2 * nRoot + 1;
        dfs(vLevelOrder,vPreOrder,nTmp);
    }
    else
        return;

    if(2 * nRoot + 2 < (int)vLevelOrder.size())
    {
        int nTmp = 2 * nRoot + 2;
        dfs(vLevelOrder,vPreOrder,nTmp);
    }
    else    
        return;
}

#endif


int main()
{  
    vector<string> vLevelOrder = getLevelOrder();
#if FUNC
    vector<string> vPreOrder = levelOrderToPreOrder(vLevelOrder);

#else

    vector<string> vPreOrder;
    int nRoot = 0;
    dfs(vLevelOrder,vPreOrder,nRoot);

#endif

    for(auto n : vPreOrder)
    {
        cout << n << endl;
    }

    return 0;
}

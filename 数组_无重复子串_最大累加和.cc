
/*
给定一个数组arr，返回arr的最长的无重复子串的长度(无重复指的是所有数字都不相同)
[2,2,3,4,3],3
[2,3,4,5],4
*/
int subVec(vector<int> arr)
{
    unordered_set<int> set;
    int n = arr.size();
    
    int right = -1;
    int max = 0;
    for(int left = 0; left < n; ++left)
    {
        if(left != 0)
        {
            //
            set.erase(arr[left - 1]);
        }

        while(right < n - 1 && !set.count(arr[right + 1]))
        {
            set.insert(arr[right + 1]);
            ++right;
        }
        max = max(max, right - left + 1);
    }
    return max;
}

/*
给定一个数组arr，返回子数组的最大累加和
例如，arr = [1, -2, 3, 5, -2, 6, -1]，所有子数组中，[3, 5, -2, 6]可以累加出最大的和12，所以返回12.
题目保证没有全为负数的数据
[要求]
时间复杂度为O(n)，空间复杂度为O(1)

[1, -2, 3, 5, -2, 6, -1]
12
*/
int maxSum(vector<int> arr)
{
    int maxSum = 0;
    for(int i = 0; i < arr.size(); ++i)
    {
        int sum = 0;
        for(int j = i; j < arr.size(); ++j)
        {
            sum += arr[j];
            if(sum > maxSum)
                maxSum = sum;
        }
    }
    return maxSum;
}
// 用动态规划来优化一下。



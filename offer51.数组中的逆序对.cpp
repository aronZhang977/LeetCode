// 双指针法  超时
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int nCount = 0;
        for(int i = 0; i != nums.size() - 1; ++i)
        {
            for(int j = nums.size() - 1; j != i; --j)
            {
                if(nums[i] > nums[j])
                    ++nCount;
            }
        }
        return nCount;
    }
};

// 分治法
/*
    归并排序是分治思想的典型应用：
    包含三个步骤
    1.分解：区间中分成两个
    2.解决：使用归并排序递归地排序两个子序列
    3.合并：把两个已经排好序的子序列 [l, m][l,m] 和 [m + 1, r][m+1,r] 合并起来
*/
class Solution {
public:
    int mergeSort(vector<int>& nums,vector<int>& tmp, int left, int right)
    {
        if(left >= right)
            return 0;
        
        int mid = (left + right) / 2;
        int inv_count = mergeSort(nums, tmp, left, mid) + mergeSort(nums, tmp, mid + 1, right);
        int i = left, j = mid + 1, pos = left;
        // 归并排序 选小的进辅助数组
        while(i <= mid && j <= right)
        {
            if(nums[i] <= nums[j])
            {
                tmp[pos] = nums[i];
                ++i;
                inv_count += (j - (mid + 1));
            }
            else{
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }
        // 剩余的左边
        for(int k = i; k <= mid; ++k)
        {
            tmp[pos++] = nums[k];
            inv_count += (j - (mid + 1));   // j 右边现在的位置 - mid+1 右边起始位置  相当于左边剩余的*右边已经过得  
        }
        // 剩余的右边
        for(int k = j; k <= right; ++k)
        {
            tmp[pos++] = nums[k];
        }
        // std::copy( InputIt first, InputIt last, OutputIt d_first );
        copy(tmp.begin() + left,tmp.begin() + right + 1,nums.begin() + left);
        return inv_count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return  mergeSort(nums, tmp, 0, n - 1);
    }
};
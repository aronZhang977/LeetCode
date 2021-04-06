/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

示例 1：

输入：[3,4,5,1,2]
输出：1
示例 2：

输入：[2,2,2,0,1]
输出：0

这题与153区别在有无重复元素

注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
*/

class Solution {
public:
    int minArray(vector<int>& numbers) {
        
        int left = 0, right = numbers.size() - 1;
        while (left <= right)
        {
           // int mid = (left + right) / 2;
            int mid = left - (left - right) / 2;
            // 小于在前边部分找  大于在后边部分找 等于则右边界前移
            if (numbers[mid] > numbers[right])
            {
                left = mid + 1;
            }
            else if (numbers[mid] < numbers[right])
            {
                right = mid;                
            }
            else
            {
                --right;
            }
        }
        return numbers[left];
    }
};



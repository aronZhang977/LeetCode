/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
             // 剑指offer：分区查找  每次选取范围右上角的数字，根据行列均递增判断下次范围
        int rows = matrix.size(), columns = matrix[0].size();
        bool found = false;

        int row = 0;
        int column = columns - 1;
        
        while (row < rows && column >= 0)
        {
            if(matrix[row][column] == target)
            {
                found = true;
                break;
            }
            else if(matrix[row][column] > target)
                --column;
            else
                ++row;            
        }
        return found;
    }

    // 这个就已经是最优解法，感觉二分意思不大。
};
// @lc code=end


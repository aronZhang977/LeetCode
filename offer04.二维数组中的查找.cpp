/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

 

示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。

*/

// 方法1： 暴力遍历
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 方法1： 暴力遍历
        for(int i = 0; i != matrix.size(); ++i)
        {
            for(int j = 0; j != matrix[i].size(); ++j)
            {
                if(target == matrix[i][j])
                    return true;
            }
        }
        return false;
    }
};

// 方法2： 线性查找   由于 每行每列 都是递增的  所以当下一个值大于当前值时后边的值就不需要再考虑了
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 方法2： 线性查找   由于 每行每列 都是递增的  所以当下一个值大于当前值时后边的值就不需要再考虑了
       for(int i = 0;i != matrix.size();++i)
       {
           for(int j = 0;j != matrix[i].size();++j)
           {
               if(target == matrix[i][j])
               {
                   return true;
               }
               else if(target < matrix[i][j])
               {
                   break;
               }
           }
       }
       return false;
    }
};

//  方法2  看起来比方法1 效率高  但是在实际LeetCode的运行中  执行时间比方法1还要多  
//    可能是  数据样本比较小，if的时间开销要比遍历的时间开销大？？？

// 在运行 主站 240 时  两种方法均超时。。。
// 需要参照 240题解，重新考虑一下

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
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

};


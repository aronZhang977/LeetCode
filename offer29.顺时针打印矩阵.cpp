class Solution {
public:
    //  这个太乱了 回头重写一下 
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = 0,columns = 0;
        int max_rows = matrix.size() - 1;
        int max_columns = matrix[0].size() - 1;

        while(max_rows && max_columns)
        {

            for(int i = rows;i != max_rows;++i)
            {
                int j = columns;
                for(; j != max_columns; ++j)
                {
                    res.push_back(matrix[i][j]);
                }
                if(j == max_columns)
                {
                    for(int k = rows;k != max_rows;++k)
                    {
                        res.push_back(matrix[k][max_columns]);
                    }
                }
            }
            ++rows;
            --max_rows;
            ++columns;
            --max_columns;
        }
        return res;    
    }

};
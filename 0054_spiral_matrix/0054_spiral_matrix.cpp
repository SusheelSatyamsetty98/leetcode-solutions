class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = 0;
        int column = -1;
        vector<int> res;

        int m = matrix.size();        // number of rows
        int n = matrix[0].size();     // number of columns

        while ((m > 0) && (n > 0))
        {
            for (int i = 0; i < n; i++)   // move right
                res.push_back(matrix[row][++column]);
            m--;

            for (int i = 0; i < m; i++)   // move down
                res.push_back(matrix[++row][column]);
            n--;

            if (m > 0) {
                for (int i = 0; i < n; i++)   // move left
                    res.push_back(matrix[row][--column]);
                m--;
            }

            if (n > 0) {
                for (int i = 0; i < m; i++)   // move up
                    res.push_back(matrix[--row][column]);
                n--;
            }
        }

        return res;  
    }
};
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size();    
        int m = matrix[0].size();
        vector<vector<int>> column(m,vector<int>(n));
        vector<int> res;  
        vector<int> temp_r;  
        vector<int> temp_c;  

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                column[i][j] = matrix[j][i];
            }
        }

        for(int i = 0; i < n; i++) temp_r.push_back(*min_element(matrix[i].begin(),matrix[i].end()));
        for(int i = 0; i < m; i++) temp_c.push_back(*max_element(column[i].begin(),column[i].end()));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j ++)
            {
                if(temp_r[j] == temp_c[i]) res.push_back(temp_c[i]);
            }
        }

        return res;
    }
};
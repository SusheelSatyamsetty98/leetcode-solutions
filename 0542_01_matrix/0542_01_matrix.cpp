class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vst(n,vector<int>(m,0));   
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)
                {
                    vst[i][j] = 1;
                    q.push({i,j});
                }
            }
        }

        int dr[] = {-1,0,0,1};
        int dc[] = {0,-1,1,0};

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [r,c] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vst[nr][nc])
                    {
                        vst[nr][nc] = 1;
                        mat[nr][nc] = mat[r][c] + 1;
                        q.push({nr,nc});
                    }
                }
            }
        }

        return mat;
    }
};
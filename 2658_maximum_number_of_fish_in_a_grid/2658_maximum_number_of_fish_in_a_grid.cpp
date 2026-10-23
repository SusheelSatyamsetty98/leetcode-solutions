class Solution {
public:
    int bfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& vst)
    {
        int n = grid.size();
        int m = grid[0].size();
        int res = grid[row][col];
        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [r,c] = q.front();
                q.pop();

                for(int i = -1; i <= 1; i++)
                {
                    for(int j = -1; j <= 1; j++)
                    {
                        if(abs(i) == abs(j)) continue;
                        int nr = r + i;
                        int nc = c + j;

                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vst[nr][nc] && grid[nr][nc] > 0)
                        {
                            vst[nr][nc] = 1;
                            res += grid[nr][nc];
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
        return res;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vst(n,vector<int>(m,0));
        int res = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vst[i][j] && grid[i][j] > 0)
                {
                    vst[i][j] = 1;
                    res = max(res,bfs(grid,i,j,vst));
                }
            }
        }

        return res;
    }
};
class Solution {
private:
    void bfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& vst, queue<pair<int,int>>& qz)
    {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        q.push({r,c});
        vst[r][c] = 1;

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [row,column] = q.front();
                q.pop();

                for(int i = -1; i <= 1; i++)
                {
                    for(int j = -1; j <= 1; j++)
                    {
                        if(abs(i) == abs(j)) continue;

                        int nr = row + i;
                        int nc = column + j;

                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vst[nr][nc])
                        {
                            vst[nr][nc] = 1;
                            if (grid[nr][nc] == 0) qz.push({nr,nc});
                            else q.push({nr,nc});
                        }
                    }
                }
            }
        }
    }

    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vst,queue<pair<int,int>>& q)
    {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [row,column] = q.front();
                q.pop();

                for(int i = -1; i <= 1; i++)
                {
                    for(int j = -1; j <= 1; j++)
                    {
                        if(abs(i) == abs(j)) continue;

                        int nr = row + i;
                        int nc = column + j;

                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vst[nr][nc])
                        {
                            vst[nr][nc] = 1;
                            if(grid[nr][nc] == 1) return res + 1;
                            else q.push({nr,nc});
                        }
                    }
                }
            }
            res++;
        }
        return res;
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>> qz;
        int res = INT_MAX;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vst(n,vector<int>(m,0));

        for(int i = 0; i < n; i++)
        {
            bool found = false;
            for(int j = 0; j < m; j++)
            {
                if(!vst[i][j] && grid[i][j] == 1)
                {
                    vst[i][j] = 1;
                    bfs(grid,i,j,vst,qz);
                    res = min(res,bfs(grid,vst,qz));
                    found = true;
                    break;
                }
            }
            if(found) break;
        }   

        return res;
    }
};
class Solution {
public:
    void bfs(vector<vector<int>>&grid, vector<vector<int>>& vst,queue<pair<int,int>>& q, bool isTrue)
    {
        int n = grid.size();
        int m = grid[0].size();

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

                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vst[nr][nc] && grid[nr][nc] == 0)
                        {
                            vst[nr][nc] = 1;
                            q.push({nr,nc});
                            if(isTrue) grid[nr][nc] = 1;
                        }
                    }
                }
            }
        }
        return;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<int>> vst(n,vector<int>(m,0));

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++)
        {
            if(!vst[i][0] && grid[i][0] == 0)
            {
                q.push({i,0});
                vst[i][0] = 1;
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(!vst[i][m-1] && grid[i][m-1] == 0)
            {
                q.push({i,m-1});
                vst[i][m-1] = 1;
            }
        }    

        for(int i = 0; i < m; i++)
        {
            if(!vst[0][i] && grid[0][i] == 0)
            {
                q.push({0,i});
                vst[0][i] = 1;
            }
        }

        for(int i = 0; i < m; i++)
        {
            if(!vst[n-1][i] && grid[n-1][i] == 0)
            {
                q.push({n-1,i});
                vst[n-1][i] = 1;
            }
        }

        bfs(grid,vst,q,true);

        for(int i = 1; i < n-1; i++)
        {
            for(int j = 1; j < m-1; j++)
            {
                if(!vst[i][j] && grid[i][j] == 0)
                {
                    q.push({i,j});
                    vst[i][j] = 1;
                    bfs(grid,vst,q,false);
                    res++;
                }
            }
        }

        return res;
    }
};
class Solution {
public:
    void solve(vector<vector<char>>& grid)
    {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vst(n,vector<int>(m,0));

        for(int i = 0; i < m; i++)
        {
            if(grid[0][i] == 'O')
            {
                vst[0][i] = 1;
                q.push({0,i});
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(grid[i][0] == 'O')
            {
                vst[i][0] = 1;
                q.push({i,0});
            }
        }
        for(int i = 0; i < m; i++)
        {
            if(grid[n-1][i] == 'O')
            {
                vst[n-1][i] = 1;
                q.push({n-1,i});
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(grid[i][m-1] == 'O')
            {
                vst[i][m-1] = 1;
                q.push({i,m-1});
            }
        }

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

                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 'O' && !vst[nr][nc])
                        {
                            vst[nr][nc] = 1;
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m;j++)
            {
                if(grid[i][j] == 'O' && !vst[i][j]) grid[i][j] = 'X';
            }
        }
        
        return;
    }
};
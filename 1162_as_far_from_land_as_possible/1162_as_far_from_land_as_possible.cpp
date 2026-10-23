class Solution {
public:
    int maxDistance(vector<vector<int>>& grid)
    {
        int n  = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vst(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int res = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                    vst[i][j] = 1;
                }
            }
        }

        if(q.empty() || q.size() == n*m) return -1;

        bool isPushed = false;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int row = q.front().first;
                int column = q.front().second;
                q.pop();

                for(int i = -1; i <= 1; i++)
                {
                    for(int j = -1; j <= 1; j++)
                    {
                        if(abs(i) == abs(j)) continue;
                        int nr = row + i;
                        int nc = column + j;
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vst[nr][nc] && grid[nr][nc] == 0)
                        {
                            vst[nr][nc] = 1;
                            q.push({nr,nc});
                            grid[nr][nc] = 1;
                            isPushed = true;
                        }
                    }
                }
            }
            if(isPushed)
            {
                isPushed = false;
                res++;
            }
        }
        return res;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2) q.push({i,j});
            }
        }

        while(!q.empty())
        {
            bool isPushed = false;
            int size = q.size();
            while(size--)
            {
                int row = q.front().first;
                int column = q.front().second;
                q.pop();

                for(int i = -1; i <= 1; i++)
                {
                    for(int j = -1; j <= 1; j++)
                    {
                        if(abs(i) == abs(j)) continue;
                        int r = row + i;
                        int c = column + j;
                        if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1)
                        {
                            grid[r][c] = 2;
                            q.push({r,c});
                            isPushed = true;
                        }
                    }
                }
            }
            if(isPushed) res++;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1) return -1;
            }
        }
        return res;
    }
};
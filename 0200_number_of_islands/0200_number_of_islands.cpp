class Solution {
public:
    void connectedIslands(vector<vector<char>>& grid,int r, int c,vector<vector<int>>& vst)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q; 
        q.push({r,c});
        vst[r][c] = 1;
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
                        int nr = row+i;
                        int nc = column+j;
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && !vst[nr][nc])
                        {
                            vst[nr][nc] = 1;
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vst(n,vector<int>(m,0));
        int  cnt = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vst[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    connectedIslands(grid,i,j,vst);
                }
            }
        }
        return cnt;
    }
};
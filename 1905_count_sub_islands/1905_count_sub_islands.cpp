class Solution {
private:
    int bfs(vector<vector<int>>& grid2, int r, int c,
             vector<vector<int>>& grid1,vector<vector<int>>& vst) {
        int res = 1;
        queue<pair<int, int>> q;
        q.push({r, c});
        int n = grid1.size();
        int m = grid1[0].size();
        vst[r][c] = 1;
        while (!q.empty()) {
            int sz = q.size();
            while(sz--)
            {
                auto [row,column] = q.front();
                q.pop();

                if(grid1[row][column] == 0) res = 0;

                for(int i = -1; i <= 1; i++)
                {
                    for(int j = -1; j <= 1; j++)
                    {
                        if(abs(i) == abs(j)) continue;

                        int nr = row + i;
                        int nc = column + j;
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vst[nr][nc] && grid2[nr][nc] == 1)
                        {
                            vst[nr][nc] = 1;
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
        return res;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int res = 0;
        queue<pair<int, int>> q;
        int n = grid1.size();
        int m = grid1[0].size();

        vector<vector<int>> vst(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vst[i][j] && grid2[i][j] == 1) 
                {
                    if(bfs(grid2, i, j,grid1,vst)) res++;
                }
            }
        }

        return res;
    }
};
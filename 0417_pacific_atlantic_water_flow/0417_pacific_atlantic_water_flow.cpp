class Solution {
public:
    void bfs (queue<pair<int,int>>& q, vector<vector<int>>& h, vector<vector<int>>& vst)
    {
        int n = h.size();
        int m = h[0].size();

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [row,column] = q.front();
                q.pop();

                for(int k = -1; k <= 1; k++)
                {
                    for(int l = -1; l <= 1; l++)
                    {
                        if(abs(k) == abs(l)) continue;
                        int nr = row + k;
                        int nc = column + l;

                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vst[nr][nc] && h[row][column] <= h[nr][nc])
                        {
                            vst[nr][nc] = 1;
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        vector<vector<int>> res;
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        queue<pair<int,int>> q;

        // Pacific
        for(int i = 0; i < m; i++) { pacific[0][i] = 1; q.push({0,i}); }
        for(int j = 1; j < n; j++) { pacific[j][0] = 1; q.push({j,0}); }
        bfs(q, h, pacific);

        // Atlantic
        for(int i = 0; i < m; i++) { atlantic[n-1][i] = 1; q.push({n-1,i}); }
        for(int j = 0; j < n-1; j++) { atlantic[j][m-1] = 1; q.push({j,m-1}); }
        bfs(q, h, atlantic);

        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }
};
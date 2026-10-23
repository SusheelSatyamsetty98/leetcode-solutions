class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isW) {
        queue<pair<int,int>> q;
        int n = isW.size();
        int m = isW[0].size();
        vector<vector<int>> vst(n,vector<int>(m,0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(isW[i][j] == 1)
                {
                    vst[i][j] = 1;
                    q.push({i,j});
                }
                isW[i][j] = !isW[i][j];
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

                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vst[nr][nc])
                        {
                            isW[nr][nc] = isW[r][c] + 1;
                            vst[nr][nc] = 1;
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
        return isW;
    }
};
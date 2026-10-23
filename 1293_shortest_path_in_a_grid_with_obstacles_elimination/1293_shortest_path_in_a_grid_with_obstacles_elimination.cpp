class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> vst(n, vector<vector<int>>(m, vector<int>(k+1, 0)));

        queue<tuple<int,int,int>> q;

        if(grid[0][0] == 1) 
        {
            k--;
        }
        q.push({0,0,k});
        vst[0][0][k] = 1;

        int res = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto top = q.front(); q.pop();
                int row = get<0>(top);
                int column = get<1>(top);
                int remaining_k = get<2>(top);

                if(row == n-1 && column == m-1) return res;

                for(int i = -1; i <= 1; i++)
                {
                    for(int j = -1; j <= 1; j++)
                    {
                        if(abs(i) == abs(j)) continue;
                        int nr = row+i;
                        int nc = column+j;
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m)
                        {
                            if(remaining_k > 0 && grid[nr][nc] == 1 && !vst[nr][nc][remaining_k-1])
                            {
                                vst[nr][nc][remaining_k-1] = 1;
                                q.push({nr,nc,remaining_k-1});
                            }

                            if(grid[nr][nc] == 0 && !vst[nr][nc][remaining_k])
                            {
                                q.push({nr,nc,remaining_k});
                                vst[nr][nc][remaining_k] = 1;
                            }
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
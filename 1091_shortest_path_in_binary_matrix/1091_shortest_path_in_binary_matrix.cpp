class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vst(n,vector<int>(n,0));    
        int res = 1;
        queue<pair<int,int>> q;

        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        q.push({0,0});

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int row = q.front().first;
                int column = q.front().second;
                q.pop();
                if(row == n-1 && column == n-1) return res;

                for(int i = -1; i <= 1; i++)
                {
                    for(int j = -1; j <= 1; j++)
                    {
                        if(i == 0 && j == 0) continue;
                        int r = row + i, c = column + j;
                        if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0)
                        {
                            grid[r][c] = 1;
                            q.push({r,c});
                        }
                    }
                }
            }
            res++;
        } 

        return -1;   
    }
};
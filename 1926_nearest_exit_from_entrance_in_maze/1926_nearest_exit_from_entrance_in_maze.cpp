class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> vst(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({ent[0],ent[1]});
        vst[ent[0]][ent[1]] = 1;
        int res = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int row = q.front().first;
                int column = q.front().second;
                q.pop();

                if((row == 0 || column == 0 || row == n-1 || column == m-1) && (row != ent[0] || column != ent[1])) return res;

                for(int i = -1; i <= 1; i++)
                {
                    for(int j = -1; j <= 1; j++)
                    {
                        if(abs(i) == abs(j)) continue;
                        int nr = row + i;
                        int nc = column + j;
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vst[nr][nc] && maze[nr][nc] == '.')
                        {
                            vst[nr][nc] = 1;
                            q.push({nr,nc});
                            maze[nr][nc] = '+';
                        }

                    }
                }
            }
            res++;
        }
        return -1;
    }
};
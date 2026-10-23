class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        queue<pair<int,int>> q;
        vector<vector<int>> vst(9,vector<int>(9,0));
        q.push({start[0],start[1]});
        vst[start[0]][start[1]] = 1;
        int res = 1;
        bool isFinished = false;
        int dr[] = {-2,-2,-1,-1,1,1,2,2};
        int dc[] = {-1,1,-2,2,-2,2,-1,1};
        int dsize = sizeof(dr)/sizeof(dr[0]);

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [r,c] = q.front();
                q.pop();

                if(r == target[0] && c == target[1])
                {
                    isFinished = true;
                    break;
                }

                for(int i = 0; i < dsize; i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && !vst[nr][nc])
                    {
                        vst[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
            if(isFinished) break;
            res++;
        }

        return (res%2);
    }
};
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<int> brd;
        int level = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(level % 2 == 0)
                for(int j = 0; j < m; j++) brd.push_back(board[i][j]);
            else
                for(int j = m-1; j >= 0; j--) brd.push_back(board[i][j]);
            level++;
        }

        vector<int> vst(n*m+1,0);
        queue<int> q;
        q.push(1);
        vst[1] = 1;
        int res = 0;

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int curr = q.front();
                q.pop();

                if(curr == n*m) return res;

                for(int i = 1; i <= 6; i++)
                {
                    int next = curr + i;
                    if(next > n*m) break;
                    if(brd[next-1] != -1) next = brd[next - 1];

                    if(!vst[next])
                    {
                        vst[next] = 1;
                        q.push(next);
                    }
                }
            }
            res++;
        }  
        return -1;      
    }
};
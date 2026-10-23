class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int res = 0;
        string str = "ACGT";
        queue<string> q;
        map<string,int> vst;
        
        q.push(start);
        vst[start] = 1;

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                string curr = q.front();
                q.pop();

                if(curr == end) return res;

                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 8; j++)
                    {
                        string neig = curr;
                        neig[j] = str[i];
                        if(find(bank.begin(), bank.end(),neig) != bank.end() && !vst[neig])
                        {
                            vst[neig] = 1;
                            q.push(neig);
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
class Solution {
public:
    int ladderLength(string start, string end, vector<string>& word) {
        unordered_set<string> wl(word.begin(), word.end());
        string str = "abcdefghijklmnopqrstuvwxyz";
        int n = str.size();

        int res = 0;
        int m = start.size();
        queue<string> q;
        q.push(start);

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                string curr = q.front();
                q.pop();

                if(curr == end) return res + 1;

                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < m; j++)
                    {
                        string neigh = curr;
                        if(neigh[j] == str[i]) continue;
                        neigh[j] = str[i];

                        // if(find(wl.begin(),wl.end(),neigh) != wl.end())
                        if(wl.count(neigh))
                        {
                            wl.erase(neigh);
                            q.push(neigh);
                        }
                    }
                }
            }
            res++;
        }    

        return 0;
    }
};
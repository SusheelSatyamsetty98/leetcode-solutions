class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int dst) {
        vector<vector<int>> adj(n+1);
        for(auto& e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vst(n+1,0);
        queue<int> q;

        q.push(source);
        vst[source] = 1;

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int top = q.front();
                q.pop();
                
                if(top == dst) return true;

                for(int i = 0; i < adj[top].size(); i++)
                {
                    if(!vst[adj[top][i]])
                    {
                        vst[adj[top][i]] = 1;
                        q.push(adj[top][i]);
                    }
                }
            }
        }
        return false;
    }
};
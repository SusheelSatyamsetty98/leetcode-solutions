class Solution {
public:
    void bfs(vector<vector<int>>& adj,int node, vector<int>& vst)
    {
        queue<int> q;
        q.push(node);
        vst[node] = 1;

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int idx = q.front();
                q.pop();

                for(int i = 0; i < adj[idx].size(); i++)
                {
                    if(!vst[adj[idx][i]])
                    {
                        vst[adj[idx][i]] = 1;
                        q.push(adj[idx][i]);
                    }
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int res = 0;
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        vector<int> vst(n);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if((isConnected[i][j] == 1) && i != j) adj[i].push_back(j);
            }
        }  

        for(int i = 0; i < n; i++)
        {
            if(!vst[i])
            {
                bfs(adj,i,vst);
                res++;
            }
        }

        return res;  
    }
};
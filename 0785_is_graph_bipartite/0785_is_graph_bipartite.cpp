class Solution {
public:
    bool bfs(vector<vector<int>>& adj,int node, vector<int>& vst)
    {
        queue<int> q;
        q.push(node);
        if(node == 0) vst[node] = 1;
        else vst[node] = !vst[node-1];

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int idx = q.front();
                q.pop();

                for(int i = 0; i < adj[idx].size(); i++)
                {
                    if(vst[adj[idx][i]] == -1)
                    {
                        vst[adj[idx][i]] = !vst[idx];
                        q.push(adj[idx][i]);
                    }
                    else if (vst[adj[idx][i]] == vst[idx]) return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> vst(n,-1);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < graph[i].size(); j++) adj[i].push_back(graph[i][j]);
        }

        for(int i = 0; i < n; i++)
        {
            if(vst[i] == -1)
            {
                if(!bfs(adj,i,vst)) return false;
            }
        }
        return true;    
    }
};
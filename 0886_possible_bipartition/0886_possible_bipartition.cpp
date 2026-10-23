class Solution {
public:
    bool bfs(vector<vector<int>> adj, int node, vector<int>& coloured)
    {
        queue<int> q;
        q.push(node);
        if(node == 1) coloured[node] = 0;
        // else coloured[node] = !coloured[node];

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto idx = q.front();
                q.pop();

                for(int i = 0; i < adj[idx].size(); i++)
                {
                    int neigh = adj[idx][i];
                    if(coloured[neigh] == -1)
                    {
                        coloured[neigh] = !coloured[idx];
                        q.push(neigh);
                    }
                    else if(coloured[neigh] == coloured[idx]) return false;
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> coloured(n+1,-1);
        vector<vector<int>> adj(n+1);

        for(int i = 0; i < dislikes.size(); i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        for(int i = 1; i <= n; i++)
        {
            sort(adj[i].begin(),adj[i].end());
            if(coloured[i] == -1)
            {
                if(!bfs(adj,i,coloured)) return false;
            }
        }
        
        return true;
    }
};
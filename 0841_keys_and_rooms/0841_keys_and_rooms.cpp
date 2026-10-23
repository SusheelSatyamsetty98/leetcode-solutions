class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vst(n+1);
        vector<vector<int>> adj(n);
        queue<int> q;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < rooms[i].size(); j++)
            {
                if(rooms[i][j] != i) adj[i].push_back(rooms[i][j]);
            }
        }

        q.push({0});
        vst[0] = 1;

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int idx = q.front();
                q.pop();

                for(int i = 0; i < adj[idx].size(); i++)
                {
                    int neigh = adj[idx][i];
                    if(!vst[neigh])
                    {
                        vst[neigh] = 1;
                        q.push(neigh);
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if(vst[i] == 0) return false;
        }
        return true;
    }
};
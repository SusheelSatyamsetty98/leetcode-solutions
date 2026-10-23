class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color)
    {
        queue<pair<int,int>> q;
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> res = img;
        vector<vector<int>> vst(n,vector<int>(m,0));

        q.push({sr,sc});
        vst[sr][sc] = 1;
        res[sr][sc] = color;
        int target_color = img[sr][sc];
        while(!q.empty())
        {
            int row = q.front().first;
            int colum = q.front().second;
            q.pop();
            for(int i = -1; i <= 1; i ++)
            {
                for(int j = -1; j <= 1; j++)
                {
                    if (abs(i) == abs(j)) continue;  // fix 1: skip diagonals
                    int temp_r = row+i;
                    int temp_c = colum+j;
                    if(temp_r >= 0 && temp_c >= 0 && temp_r < n && temp_c < m && !vst[temp_r][temp_c] && img[temp_r][temp_c] == target_color)
                    {
                        vst[temp_r][temp_c] = 1;
                        q.push({temp_r,temp_c});
                        res[temp_r][temp_c] = color;
                    }
                }
            }
        }

        return res;        
    }
};
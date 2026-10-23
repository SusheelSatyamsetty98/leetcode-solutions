class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        int s_size = s.size();
        int g_size = goal.size();

        if(s_size != g_size)
        {
            return false;
        }

        string con = goal + goal;

        return con.find(s) != string::npos;
    }
};
class Solution{
    public:
        void helpFn(int open, int close,int n, string temp, vector<string>& ans)
        {
            if(open == n)
            {
                if(close != n)
                {
                    int x = n - close;
                    for(int i = 0; i < x; i++)
                        temp.push_back(')');
                }
                ans.push_back(temp);
                // cout <<" here" << temp << endl;
                return;
            }
            
            if(close > open)
            {
                return;
            }
            
            if(open < n)
            {
                temp.push_back('(');
            }
            
            helpFn(open+1,close, n,temp,ans);
            temp.pop_back();
            
            if(close < open)
            {
                temp.push_back(')');
                helpFn(open, close+1, n, temp, ans);
            }
        }
        
        vector<string> generateParenthesis(int n)
        {
            string temp;
            vector<string> ans;
            
            temp.push_back('(');
            
            helpFn(0,-1,n-1,temp,ans);
            return ans;
        }
};
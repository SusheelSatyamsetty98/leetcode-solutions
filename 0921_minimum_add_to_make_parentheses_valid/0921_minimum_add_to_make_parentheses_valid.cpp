class Solution {
public:
    int minAddToMakeValid(string s)
    {
        int n = s.size();
        
        if(n == 1)
        {
            return 1;
        }
        
        stack<char> st;
        int res = 0;

        for(char i : s)
        {
            if(i == '(')
            {
                st.push(i);
            }
            else
            {
                if (st.size() > 0)
                {
                    if((i == ')') && (st.top() != '('))
                    {
                        st.push(i);
                    }
                    else
                    {
                        st.pop();
                    }
                }
                else
                {
                    st.push(i);
                }
            }

        } 
        
        return st.size();
    }
};
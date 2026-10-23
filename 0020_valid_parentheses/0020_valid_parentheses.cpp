class Solution {
public:
    bool isValid(string s)
    {
        int n = s.size();
        
        if(n == 1)
        {
            return false;
        }
        
        stack<char> st;

        for(char i : s)
        {
            if((i == '(') || (i == '[') || (i == '{'))
            {
                st.push(i);
            }
            else
            {
                if (st.size() > 0)
                {
                    if(((i == ')') && (st.top() != '(')) ||
                        ((i == ']') && (st.top() != '[')) ||
                        ((i == '}') && (st.top() != '{')))
                    {
                        return false;
                    }
                    else
                    {
                        st.pop();
                    }
                }
                else
                {
                    return false;
                }
            }

        } 
        
        if (st.size() == 0)
            return true;
        else
            return false;
    }
};
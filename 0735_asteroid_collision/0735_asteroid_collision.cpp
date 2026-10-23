class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as)
    {
        stack<int> st;
        int n = as.size();
        
        if (n == 0) return {};
        
        st.push(as[0]);
        int i = 1;
        
        while(i < n)
        {
            if (st.empty() || as[i] > 0 || st.top() < 0)
            {
                st.push(as[i]);
                i++;
                continue;
            }

            if(!st.empty() && (st.top() + as[i] == 0))
            {
                st.pop();
                i++;
                continue;
            }
            
            if (!st.empty() && st.top() > 0 && as[i] < 0)
            {
                if ((st.top() + as[i]) > 0)
                {
                    i++; 
                }
                else
                {
                    st.pop();
                }
                continue;
            }
        }

        vector<int> res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
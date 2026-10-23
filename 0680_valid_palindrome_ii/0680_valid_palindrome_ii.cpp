class Solution {
public:
    
    bool isPalindorme(string s, int i, int j)
    {
        while(i < j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        
        while(i < j)
        {
            if(s[i] != s[j])
            {
                if(s[i+1] == s[j])
                {
                    if(isPalindorme(s,i+1,j))
                    {
                        break;
                    }
                }  
                
                if (s[i] == s[j-1])
                {
                    if(isPalindorme(s,i,j-1))
                    {
                        break;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            
            i++;
            j--;
        }
        return true;
    }
};
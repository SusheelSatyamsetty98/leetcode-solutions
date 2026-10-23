class Solution {
public:
    string reverse_invert(string str)
    {
        string temp(str.size(), ' '); 
        int n = str.size();
    
        for (char ch : str)
        {
            temp[--n] = (ch == '0') ? '1' : '0';
        }
    
        return temp;
    }
    
    void helpFn(int n, string& str)
    {
        string  temp_str;
        if(n <= 1)
        {
            str.append("0");
            return;
        }
        
        helpFn(n-1, temp_str);
        str = temp_str+"1"+reverse_invert(temp_str);
        return;
        
    }
    
    char findKthBit(int n, int k)
    {
       string str;
    
       helpFn(n,str);
       
       return str[k-1];
    }
};
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
    string res = to_string(n);
    int sz = res.size();
    int mark = sz;  // position from where all digits become '9'
    
    for(int i = sz-1; i > 0; i--) {
        if(res[i-1] > res[i]) {
            res[i-1]--;
            mark = i;
        }
    }
    for(int i = mark; i < sz; i++) res[i] = '9';
    
    return stoi(res);
    }
};
class Solution {
public:
    static bool compareVectors(const vector<int>& a, const vector<int>& b) {
    if (a[0] != b[0]) {
        return a[0] < b[0];
    }
    return a[1] > b[1];
    }

    int numberOfPairs(vector<vector<int>>& p) {
        int res = 0;
        sort(p.begin(), p.end(), compareVectors);
        int Ax, Ay, Bx, By;
        int sz = p.size();
        for(int i = 0 ; i < sz; i++)
        {
            int tempMinY = -1;
            Ax = p[i][0];
            Ay = p[i][1];
            int prevX = -1;
            bool isUpdate = false;
            for(int j = i+1; j < sz; j++)
            {
                Bx = p[j][0];
                By = p[j][1];
                if(prevX > 0 && prevX == Bx && isUpdate) continue;
                if(prevX != Bx && isUpdate) isUpdate = false;
                if((Ay >= By) && (tempMinY < min(Ay,By)))
                {
                    tempMinY = min(Ay,By);
                    res++;
                    if(prevX == Bx) isUpdate = true;
                }
                prevX = Bx;
            }
        }        
        return res;
    }
};
class Solution {
public:
    int maxArea(vector<int>& a) {
        int i = 0;
        int j = a.size()-1;
        int area = 0;
        while(i < j)
        {
            area = max(area, (j-i) * min(a[i],a[j]));
            if(a[i] < a[j]) i++;
            else if (a[i] > a[j]) j--;
            else
            {
                i++;
                j--;
            }
        }
        return area;
    }
};
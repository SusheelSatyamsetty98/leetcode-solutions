class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int l;
        int r = card.size()-1;
        int sum = 0;

        for(l = 0; l < k; l++) sum += card[l];
        // cout << sum << endl;
        int res = sum;
        l--;

        for(int i = 0; i < k; i++,l--,r--)
        {
            sum = abs(sum-card[l])+card[r];
            // cout << card[l] << " " << card[r] << sum << endl;
            res = max(res,sum);
        }

        return res;
    }
};
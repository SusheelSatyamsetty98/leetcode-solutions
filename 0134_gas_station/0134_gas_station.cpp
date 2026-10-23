class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalFuel = 0, currentFuel = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            totalFuel += diff;
            currentFuel += diff;
            if (currentFuel < 0) {
                start = i + 1;
                currentFuel = 0;
            }
        }
        return totalFuel >= 0 ? start : -1;
    }
};
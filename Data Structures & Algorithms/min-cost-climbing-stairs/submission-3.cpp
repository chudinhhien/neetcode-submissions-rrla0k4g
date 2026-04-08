class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int index = 0;

        int n = cost.size();

        vector<int> minCost(n);

        minCost[0] = cost[0];
        minCost[1] = cost[1];

        for(int i = 2 ; i < n ; i++) {
            minCost[i] = min(minCost[i - 1], minCost[i - 2]) + cost[i];
        }

        return min(minCost[n - 1], minCost[n - 2]);
    }
};
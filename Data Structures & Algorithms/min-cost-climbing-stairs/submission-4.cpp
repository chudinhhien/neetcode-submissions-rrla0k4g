class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int index = 0;

        int n = cost.size();

        int minCost1 = cost[0];
        int minCost2 = cost[1];

        for(int i = 2 ; i < n ; i++) {
            int minCurrentCost = min(minCost1, minCost2) + cost[i];
            minCost1 = minCost2;
            minCost2 = minCurrentCost;
        }

        return min(minCost1, minCost2);
    }
};
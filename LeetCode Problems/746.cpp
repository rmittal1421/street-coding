class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 0) return 0;
        else if(cost.size() == 1) return cost[0];
        vector<int> A(cost.size());
        
        for (int i=cost.size() - 1; i >= 0; i--) {
            if ((i == cost.size() - 1) || (i == cost.size() - 2)) A[i] = cost[i];
            else A[i] = min(cost[i] + A[i+1], cost[i] + A[i+2]);
        }
        
        return min(A[0], A[1]);
    }
};
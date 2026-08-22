class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
       // vector<int> dp(n+1);
        int prev2=0;
        int prev1=0;
        int current=0;
        for(int i=2 ;i<=n ;i++){
            current=min((prev1+cost[i-1]),(prev2+cost[i-2]));
            prev2=prev1;
            prev1=current;
        }
        return prev1;
    }
};

// class Solution {
// public:
//     int solve(vector<int>& cost, int i, vector<int>& dp) {

//         if(i <= 1)
//             return 0;

//         if(dp[i] != -1)
//             return dp[i];

//         dp[i] = min(
//             solve(cost, i - 1, dp) + cost[i - 1],
//             solve(cost, i - 2, dp) + cost[i - 2]
//         );

//         return dp[i];
//     }

//     int minCostClimbingStairs(vector<int>& cost) {

//         int n = cost.size();

//         vector<int> dp(n + 1, -1);

//         return solve(cost, n, dp);
//     }
// };


// class Solution {
// public:
    
//     int climbStairs(int n) {
//         if(n <= 2) return n;
//         // isme variable leke solve kaiya hai isse SC kam hogi
//         int first = 1;
//         int second= 2;
//          int result=0;
//          for(int i = 3; i <= n; i++) {
//             result = first + second;
//             first = second;
//             second = result;
//         }
//         return result;
//     }
// };

// isme array leke kiya hai isse thodi SC jada aaygi 
 class Solution {
public:
    int helper(int n,vector<int> & dp){
        if (n <= 2) return n;
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = helper(n-1,dp) + helper(n-2,dp);

    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
        
        }
}; 
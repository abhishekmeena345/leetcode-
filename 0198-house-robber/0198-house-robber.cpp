class Solution {
public:
    /* int f(int ind  ,vector<int>& nums,vector<int>& dp ){
        // it is a memoization method : top->bottom
        if(ind==0)return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+f(ind-2,nums,dp);
        int notpick=0+f(ind-1,nums,dp);
        return dp[ind]=max(pick,notpick);

    } */
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        int prev1=nums[0];
        int prev2=max(nums[0],nums[1]);
        int result=prev2;
        for(int i=2;i<n;i++){

            result=max(prev2 , prev1+nums[i]);
            prev1=prev2;
            prev2=result;

        }
        return result;
    }
};

// if we use only recursion not dp so it gives time limit exceeded error 


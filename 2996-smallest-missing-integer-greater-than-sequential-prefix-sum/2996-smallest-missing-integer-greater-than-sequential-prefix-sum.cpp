class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int prefixsum=nums[0];
        for(int i=1;i<n ;i++){
            if(nums[i]-nums[i-1]==1) {
                prefixsum+=nums[i];
            }
            else {
                break;
            }
        }
        map<int,int>mp;
        for(int x : nums){
             mp[x];
        }
        while(true){
           if(mp.find(prefixsum) != mp.end()){
            prefixsum++;
           }
            else {
                return prefixsum;
            }
        }
    }
};
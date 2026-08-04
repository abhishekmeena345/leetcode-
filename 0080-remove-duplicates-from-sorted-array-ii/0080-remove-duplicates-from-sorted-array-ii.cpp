class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int l=2;
        // for(int i=2;i<nums.size();i++){
        //     if(nums[i-2]==nums[i] && nums[i]==nums[i+1]) {
        //         continue;
        //     }
        //     else nums[l]=nums[i];

        // }
        // return nums;
        vector<int>arr;
        map<int , int>mp;
        for(int x : nums){
            mp[x]++;
        }
        for(auto it : mp ){
            int first=it.first;
            int second=it.second;
            int i=1;
            while(i<=2 && i<=second){
                arr.push_back(first);
                i++;
            }
        }
          nums = arr;

        return nums.size();
    }
};
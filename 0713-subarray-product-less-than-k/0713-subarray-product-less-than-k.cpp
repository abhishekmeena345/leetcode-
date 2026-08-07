class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt=0;
        for(int i =0;i<nums.size();i++){
            long long   p=1;
            for(int j=i;j<nums.size();j++){
                if (p > LLONG_MAX / nums[j])
                    break;
                p*=nums[j];
                if(p<k) cnt++;
            }
        }
        return cnt;
    }
};
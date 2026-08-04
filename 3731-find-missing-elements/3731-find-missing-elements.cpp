class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        vector<int> arr;

        if (nums.empty()) {
            return arr;
        }

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {

            // Duplicate element ko skip karo
            if (nums[i] == nums[i - 1]) {
                continue;
            }

            // nums[i-1] aur nums[i] ke beech missing elements
            for (int num = nums[i - 1] + 1; num < nums[i]; num++) {
                arr.push_back(num);
            }
        }

        return arr;
    }
};



/* sort(nums.begin(), nums.end());

        int mini = nums[0];
        int maxi = nums[n - 1];

        vector<int> arr;

        int j = 0;

        for (int i = mini; i <= maxi; i++) {

            if (j < n && nums[j] == i) {
                j++;
            }
            else {
                arr.push_back(i);
            }
        }

     return arr; */    
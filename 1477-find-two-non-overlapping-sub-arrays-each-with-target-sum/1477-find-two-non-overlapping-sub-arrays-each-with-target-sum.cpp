

// class Solution {
// public:
//     int minSumOfLengths(vector<int>& arr, int target) {
//         int n = arr.size();

//         int l = 0;
//         int r = 0;
//         int sum = 0;
//         int len = 0;

//         vector<int> nums;

//         while (r < n) {

//             sum += arr[r]; 

//             while (sum > target) {
//                 sum -= arr[l];
//                 l++;
//             }

//             if (sum == target) {
//                 len = r - l + 1;

//                 nums.push_back(len);

//                 l = r + 1;
//                 sum = 0; 
//             }

//             r++;
//         }

//         sort(nums.begin(), nums.end());

//         if (nums.size() < 2)
//             return -1;

//         return nums[0] + nums[1];
//     }
// };

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> best(n, INT_MAX);

        int l = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int r = 0; r < n; r++) {
            sum += arr[r];

            while (sum > target) {
                sum -= arr[l];
                l++;
            }

            if (sum == target) {
                int len = r - l + 1;

                // Current subarray starts at l.
                // Previous subarray must end before l.
                if (l > 0 && best[l - 1] != INT_MAX) {
                    ans = min(ans, len + best[l - 1]);
                }

                // Best subarray till r
                if (r == 0)
                    best[r] = len;
                else
                    best[r] = min(best[r - 1], len);
            }
            else {
                if (r > 0)
                    best[r] = best[r - 1];
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
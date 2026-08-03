/* class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        int l = 0;
        int r = 0;

      sort(nums1.begin(), nums1.end()
      sort(nums2.begin(), nums2.end());

        int n = nums1.size();
        int m = nums2.size();

        vector<int> arr;
        while (l < n && r < m) {

            if (nums1[l] == nums2[r]) {
                arr.push_back(nums1[l]);
                l++;
                r++;
            }

            else if (nums1[l] < nums2[r]) {
                l++;
            }

            else {
                r++;
            }
        }
        if (arr.empty()) {
            return arr;
        }

        int res = 1;

        for (int i = 1; i < arr.size(); i++) {

            if (arr[i] != arr[i - 1]) {
                arr[res] = arr[i];
                res++;
            }
        }

        arr.resize(res);

        return arr;
    }
}; */


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> st(nums1.begin(), nums1.end());

        unordered_set<int> ans;

        for (int num : nums2) {
            if (st.find(num) != st.end()) {
                ans.insert(num);
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};
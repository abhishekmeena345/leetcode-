class Solution {
public:
    void findcombinatoin(int ind, vector<int>& candidates, int target,
                         vector<vector<int>>& ans, vector<int>& ds) {

        if (ind == candidates.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if (candidates[ind] <= target) {
            ds.push_back(candidates[ind]);
            findcombinatoin(ind, candidates, target - candidates[ind], ans, ds);
            ds.pop_back();
        }

        findcombinatoin(ind + 1, candidates, target, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findcombinatoin(0, candidates, target, ans, ds);
        return ans;
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
         > pq;
         vector<int>nums;
         for(int i=0;i<arr.size();i++){
            int deff = abs(x-arr[i]);
            pq.push({deff,arr[i]});
         }
         int i=0;
         while(i<k){
            nums.push_back(pq.top().second);
            pq.pop();
            i++;
         }
         sort(nums.begin(), nums.end());
         return nums;
    }
};
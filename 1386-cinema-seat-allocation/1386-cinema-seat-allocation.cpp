class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> mp;

        // Store reserved seats as a bitmask for each row
        for(auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            mp[row] |= (1 << col);
        }

        int ans = (n - mp.size()) * 2;

        for(auto &[row, mask] : mp) {

            bool left = (mask & (1 << 2)) == 0 &&
                        (mask & (1 << 3)) == 0 &&
                        (mask & (1 << 4)) == 0 &&
                        (mask & (1 << 5)) == 0;

            bool middle = (mask & (1 << 4)) == 0 &&
                          (mask & (1 << 5)) == 0 &&
                          (mask & (1 << 6)) == 0 &&
                          (mask & (1 << 7)) == 0;

            bool right = (mask & (1 << 6)) == 0 &&
                         (mask & (1 << 7)) == 0 &&
                         (mask & (1 << 8)) == 0 &&
                         (mask & (1 << 9)) == 0;

            if(left && right)
                ans += 2;
            else if(left || middle || right)
                ans += 1;
        }

        return ans;
    }
};


// class Solution {
// public:
//     int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
//     unordered_map<int, vector<int>> mp;
//     for(auto &v : reservedSeats) {
//         mp[v[0]].push_back(v[1]);
//     }
//     int ans;
//     for(int i=0;i<n;i++){
//          int cnt=0;
//         for(int j=1;j<9;j++){
//             if(mp.find(i) != mp.end()) {
//                 if(find(mp[i].begin(), mp[i].end(), j) != mp[i].end()) {
//                     cnt=0;
//                 }
//             }
//             else {
//                 cnt++;
//             }
//             if(cnt==4){
//                 ans++;
//                 cnt=0;
//             }
//         }
//     }
//     return ans;
        
//     }
// };
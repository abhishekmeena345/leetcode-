class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        int l = 0;
        int r = 9;

        map<string, int> mp;
        vector<string> result;

        if (n < 10)
            return result;

        while (r < n) {

            string ans = s.substr(l, 10);

            mp[ans]++;

            if (mp[ans] == 2) {
                result.push_back(ans);
            }

            l++;
            r++;
        }

        return result;
    }
};

// class Solution {
// public:
//     vector<string> findRepeatedDnaSequences(string s) {
//         int n=s.size();
//         int l=0;
//         int r=9;
//         map<string,int>mp;
//         string result="";
//         for(int i=0;i<10;i++){
//             ans+=s[i];
//         }
//         mp[ans]++;
//         while(r<n){
//             string ans = s.substr(l, 10);
//             mp[ans]++;
//.            if(mp[ans]==2) result.push_back(ans);
//             r++;
//             l++;
            
//         }
//         return result;
        
//     }
// };
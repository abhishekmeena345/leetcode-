class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n= s.size();
        int l=0;
        int r=0;
        int maxlen=0;
        unordered_map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>=3){
                mp[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
class Solution {
public:
    bool wordPattern(string pattern, string s) {

        int n = s.size();
        vector<string> words;

        int i = 0;

        while(i < n) {
            string str = "";

            while(i < n && s[i] != ' ') {
                str += s[i];
                i++;
            }

            words.push_back(str);
            i++;
        }

        // Number of pattern characters and words must be same
        if(pattern.size() != words.size())
            return false;

        map<char, string> mp;
        map<string, char> mp2;

        for(int i = 0; i < pattern.size(); i++) {

            // Existing mapping check
            if(mp.find(pattern[i]) != mp.end()) {
                if(mp[pattern[i]] != words[i])
                    return false;
            }

            // Existing reverse mapping check
            if(mp2.find(words[i]) != mp2.end()) {
                if(mp2[words[i]] != pattern[i])
                    return false;
            }

            mp[pattern[i]] = words[i];
            mp2[words[i]] = pattern[i];
        }

        return true;
    }
};
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);

        // Last occurrence of every character
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<bool> visited(26, false);
        string st;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            // Agar character already answer me hai to skip
            if (visited[ch - 'a'])
                continue;

            // Jab tak stack ka top bada hai aur wo future me dubara milega
            while (!st.empty() &&
                   st.back() > ch &&
                   last[st.back() - 'a'] > i) {
                visited[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return st;
    }
};

/* class Solution {
public:
    string smallestSubsequence(string s) {
        string store = "";
        char mini = *min_element(s.begin(), s.end());
        int cnt=0;
        for (char ch : s) {
            if (mini==ch) cnt=1;
            if(cnt==1) store+=ch;

        }

        map<char, int> mp;

        for (char ch : store) {
            mp[ch]++;
        }

        string ans;

        for (auto it : mp) {
            ans += it.first;
        }

        return ans;
    }
}; */
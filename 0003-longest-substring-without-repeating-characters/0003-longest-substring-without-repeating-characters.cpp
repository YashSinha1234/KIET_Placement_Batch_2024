class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp; 
    int st = 0; 
    int max_len = 0;

    for (int e = 0; e < s.length(); e++) {
        if (mp.find(s[e]) != mp.end() && mp[s[e]] >= st) {
            st = mp[s[e]] + 1;
        }
        mp[s[e]] = e;
        max_len = max(max_len, e - st + 1);
    }

    return max_len;
    }
};
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
    int n = s.size();
    vector<int> first(26, n);
    vector<int> last(26, -1);
    for(int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        first[idx] = min(first[idx], i);
        last[idx] = max(last[idx], i);
    }
    for(int i = 0; i < 26; i++) {
        int l = first[i];
        int r = last[i];
        for(int j = l + 1; j < r; j++) { 
            int idx = s[j] - 'a';
            l = min(l, first[idx]); 
            r = max(r, last[idx]);
        }
        first[i] = l;
        last[i] = r;
    }

  
    vector<vector<int> > subs;
    for(int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        if(first[idx] == i) { 
            int r = last[idx];
            if(!subs.empty() && subs.back()[1] > r) {
                subs.pop_back();
            }
            subs.push_back({i, r});
        }
    }
    vector<string> res;
    for(int i = 0; i < subs.size(); i++) {
        int l = subs[i][0];
        int r = subs[i][1];
        res.push_back(s.substr(l, r - l +1));
    }
    return res;
    }
};
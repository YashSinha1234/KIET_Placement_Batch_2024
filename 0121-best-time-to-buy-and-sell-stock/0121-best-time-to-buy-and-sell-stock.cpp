class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int yash = INT_MAX;
    int res = 0;
    for (int i = 0; i < prices.size(); i++) {
        res = max(res, prices[i] - yash);
        yash = min(yash, prices[i]);
    }
    return res;
    }
};
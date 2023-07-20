class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 0) return 0; 
        sort(nums.begin(), nums.end());
        int mxlen = 0, curr_len = 1; 
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1] + 1) curr_len++;
            else if(nums[i] != nums[i - 1]){
                mxlen = max(mxlen, curr_len);  
                curr_len = 1; 
            }
        }
        mxlen = max(mxlen, curr_len);
        return mxlen; 
    }
};
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> powers_of_2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            powers_of_2[i] = (powers_of_2[i - 1] * 2) % MOD;
        }
        
        int left = 0, right = n - 1;
        int result = 0;
        
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + powers_of_2[right - left]) % MOD;
                ++left;
            } else {
                --right;
            }
        }
        
        return result;
    }
};
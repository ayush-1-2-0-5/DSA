class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        vector<int> dp(n,1);
        vector<int> previousIndex(n,-1);

        int maxSubsetSize = 1;
        int maxSubsetIndex = 0;

        for(int i=1; i<n; ++i) {
            for(int j=0; j<i; ++j) {
                if(nums[i] % nums[j] == 0 && 1+dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    previousIndex[i] = j;
                }
            }
            if(dp[i] > maxSubsetSize) {
                maxSubsetSize = dp[i];
                maxSubsetIndex = i;
            }
        }

        vector<int> largestSubset;
        while(maxSubsetIndex != -1) {
            largestSubset.push_back(nums[maxSubsetIndex]);
            maxSubsetIndex = previousIndex[maxSubsetIndex];
        }
        reverse(largestSubset.begin(), largestSubset.end());

        return largestSubset;
    }
};

class Solution {
public:
    int fun(vector<int> &nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> count;
        int n = nums.size();
        int r = 0;
        int l = 0;
        int ans = 0;
        
        while (r < n) {
            count[nums[r]]++;
            
            while (count.size() > k) {
                count[nums[l]]--;
                if (count[nums[l]] == 0) {
                    count.erase(nums[l]);
                }
                l++;
            }
            
            ans += r - l + 1;
            r++;
        }
        
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums, k) - fun(nums, k - 1);
    }
};

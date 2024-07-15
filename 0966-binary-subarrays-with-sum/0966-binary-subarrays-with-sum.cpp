class Solution {
public:
    int f(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int temp = 0;
        int ans = 0;

        while (r < n) {
            temp += nums[r];

            while (temp > goal) {
                temp -= nums[l];
                l++;
            }

            ans += r - l + 1;
            r++;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums, goal) - f(nums, goal - 1);
    }
};

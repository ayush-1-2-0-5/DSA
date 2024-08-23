class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int x) {
        int n = nums.size();
        int left = lowerBound(nums, x, n);
        int right = upperBound(nums, x, n);

        if (left == n || nums[left] != x) {
            return {-1, -1};
        }

        return {left, right - 1};
    }

private:
    int lowerBound(vector<int>& nums, int x, int n) {
        int hi = n - 1;
        int lo = 0;
        int ans = n;

        while (hi >= lo) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] >= x) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }

    int upperBound(vector<int>& nums, int x, int n) {
        int hi = n - 1;
        int lo = 0;
        int ans = n;

        while (hi >= lo) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] > x) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
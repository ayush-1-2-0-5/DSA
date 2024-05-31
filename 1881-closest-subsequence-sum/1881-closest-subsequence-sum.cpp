class Solution {
public:
        void generateSubsetSums(vector<int>& nums, int start, int end, vector<int>& subsetSums) {
        int n = end - start;
        for (int i = 0; i < (1 << n); ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    sum += nums[start + j];
                }
            }
            subsetSums.push_back(sum);
        }
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> a, b;

        generateSubsetSums(nums, 0, n / 2, a);
        generateSubsetSums(nums, n / 2, n, b);

        sort(b.begin(), b.end());

        int min_diff = INT_MAX;

        for (auto sum_a : a) {
            int target = goal - sum_a;
            auto it = lower_bound(b.begin(), b.end(), target);

            if (it != b.end()) {
                min_diff = min(min_diff, abs(target - *it));
            }
            if (it != b.begin()) {
                --it;
                min_diff = min(min_diff, abs(target - *it));
            }
        }

        return min_diff;
    }
};
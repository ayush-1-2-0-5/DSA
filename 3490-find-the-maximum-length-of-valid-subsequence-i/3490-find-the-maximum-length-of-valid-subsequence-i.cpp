class Solution {
public:
    int maximumLength(vector<int>& nums) {
        if (nums.empty()) return 0;  

        for (auto &i : nums) {
            i %= 2;
        }

        int c1 = 0, c2 = 0, c3 = 0;

        bool f = nums[0] % 2 ? false : true;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0)
                c1++;

            if (nums[i] % 2 == 1)
                c2++;

            if (f == false && nums[i] % 2) {
                f = !f;
                c3++;
            }

            if (f == true && nums[i] % 2 == 0) {
                f = !f;
                c3++;
            }
        }
        return max(c1, max(c2, c3));
    }
};

#include <vector>
#include <algorithm>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        int ans = it - nums.begin(); 
        return ans;
    }
};

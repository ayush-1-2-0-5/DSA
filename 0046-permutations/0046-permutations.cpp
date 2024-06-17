class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &templist, vector<int> &nums) {
        if (templist.size() == nums.size()) {
            ans.push_back(templist);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (find(templist.begin(), templist.end(), nums[i]) != templist.end()) {
                continue;
            }
            templist.push_back(nums[i]);
            backtrack(ans, templist, nums);
            templist.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> templist;
        vector<vector<int>> ans;

        backtrack(ans, templist, nums);

        return ans;
    }
};

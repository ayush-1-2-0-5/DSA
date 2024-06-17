class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& temp, vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
            if (target - candidates[i] >= 0) { 
                temp.push_back(candidates[i]);
                backtrack(ans, temp, candidates, target - candidates[i], i); 
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans, temp, candidates, target, 0);
        return ans;
    }
};

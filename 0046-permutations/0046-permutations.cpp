class Solution {
public:
     void traverse(vector<int> &temp,vector<vector<int>> &ans,vector<int> &nums)
     {
        if(nums.size()==temp.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();++i)
        {
            if (find(temp.begin(), temp.end(), nums[i]) != temp.end()) {
                continue;
            }
            temp.push_back(nums[i]);
            traverse(temp,ans,nums);
            temp.pop_back();
        }
     }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        traverse(temp,ans,nums);
        return ans;
    }
};
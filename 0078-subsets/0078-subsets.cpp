class Solution {
public:

void backtrack(vector<vector<int>> &ans,vector<int> &temp,vector<int> &nums,int k ,int start)
{
    if(temp.size()==k)
    {
        ans.push_back(temp);
        return;
    }

    for(int i=start;i<nums.size();++i)
    {
        temp.push_back(nums[i]);
        backtrack(ans,temp,nums,k,i+1);
        temp.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=0;i<=nums.size();++i)
        {
            backtrack(ans,temp,nums,i,0);
        }
        return ans;
    }

};
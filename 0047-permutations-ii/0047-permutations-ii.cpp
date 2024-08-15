class Solution {
public:

 void permute(vector<int> &nums ,set<vector<int>> &ans,int i)
    {
        int n=nums.size();
        if(i==n)
        {
        ans.insert(nums);
        return;
        }
        for(int j=i;j<n;++j)
        {
            swap(nums[i],nums[j]);
            permute(nums,ans,i+1);

            swap(nums[i],nums[j]);
        }


    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;

        permute(nums,st,0);

      vector<vector<int>> ans;

      for(auto it: st)
      {
          ans.push_back(it);
      }

return ans;
    }
};
class Solution {
public:
  bool targetsum(vector<int>& nums,int target)
  {
    int n=nums.size();
    vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
    for(int i=0;i<n+1;++i)
    {
        dp[i][0]=true;
    }
    for(int i=1;i<n+1;++i)
    {
        for(int j=1;j<target+1;++j)
        {
            if(j>=nums[i-1])
            dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
            else 
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][target];
  }
    bool canPartition(vector<int>& nums) {
        int s=0;
        for(auto it: nums)
        {
            s+=it;
        }

        if(s%2)
        return false;

        int target =s/2;
        return targetsum(nums,target);
    
    }
};
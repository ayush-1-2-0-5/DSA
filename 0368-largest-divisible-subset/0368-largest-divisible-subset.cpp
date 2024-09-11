class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
sort(nums.begin(),nums.end());
        vector<int> idx(n,-1);
        int maxsz=1;
        int maxidx=0;



        for(int i=1;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    idx[i]=j;
                }


            }
            if(dp[i]>maxsz)
            {
                maxsz=dp[i];
                maxidx=i;
             }
        }
         
vector<int> ans;
         while(maxidx!=-1)
         {
              ans.push_back(nums[maxidx]);
              maxidx=idx[maxidx];
         }

         reverse(ans.begin(),ans.end());

         return ans;
    }
};
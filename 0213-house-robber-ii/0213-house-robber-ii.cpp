class Solution {
public:

    int f(vector<int> arr,int n,vector<int> &dp)
    {
        dp[0]=arr[0];

        for(int i=1;i<n;++i)
        {
            int p=arr[i];

            if(i>1)
            p+=dp[i-2];

            int notp=dp[i-1];

            dp[i]=max(p,notp);
        }

        return dp[n-1];
    }
    int rob(vector<int>& nums) {
         int n=nums.size();
        if(n==1)
        return nums[0];
        vector<int> a2;
        vector<int> a1;
        for(int i=0,j=1;i<n-1;++i,++j)
        {
            a1.push_back(nums[i]);
            a2.push_back(nums[j]);
        }
        vector<int> dp(n-1,0);
        int a=f(a1,n-1,dp);
        dp.resize(n-1,0);

        int b=f(a2,n-1,dp);

        return max(a,b);
    }
};
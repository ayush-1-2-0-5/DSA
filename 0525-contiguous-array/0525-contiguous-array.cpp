class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int ans=0;int s=0;

        for(int i=0;i<nums.size();++i)
        {
             s+=(nums[i]==0)?-1:1;
             if(mp.find(s)!=mp.end())
             {
                ans=max(ans,i-mp[s]);

             }

             else
             {
                mp[s]=i;
             }
        }

        return ans;
    }
};
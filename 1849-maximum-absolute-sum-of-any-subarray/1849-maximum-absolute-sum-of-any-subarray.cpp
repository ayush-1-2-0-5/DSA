class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();

        vector<int> maxi(n,0);
        vector<int> mini(n,0);
     maxi[0]=mini[0]=nums[0];
     for(int i=1;i<n;++i)
     {
        maxi[i]=max(nums[i],maxi[i-1]+nums[i]);
        mini[i]=min(nums[i],mini[i-1]+nums[i]);
     }

     int ans=0;
     for(int i=0;i<n;++i)
     {
        ans=max(ans,abs(mini[i]));
        ans=max(ans,abs(maxi[i]));
     }

    return ans;
    }
};
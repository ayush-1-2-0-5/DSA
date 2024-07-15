class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int n=nums.size();
        for(int i=0;i<k;++i)
        {
          l+=nums[i]; 
        }
        int ans=l;
       int ptr=1;
        for(int i=k-1;i>=0;--i)
        { 
            l-=nums[i];
            r+=nums[n-ptr];
            ptr++;
             ans=max(ans,l+r);
        }
        return ans;
    }
};
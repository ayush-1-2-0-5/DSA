class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;

        int minpos=-1;
        int maxpos=-1;
        int ci=-1;
        int i=0;
        while(i<nums.size())
        {
           int val=nums[i];
           if(val==minK)
           {
            minpos=i;
           }
           if(val==maxK)
           {
            maxpos=i;
           }
            if(val>maxK || val<minK)
            {
                ci=i;
            }
           int temp=min(minpos,maxpos)-ci;
           temp>0?ans+=temp:ans=ans;
           i++;
        }
        return ans;
    }
};
class Solution {
public:
    int search(vector<int>& nums, int t) {
        int hi=nums.size();
        int lo=0;
        if(t>nums[hi-1] || t<nums[lo])
        {
        return -1;
        }
        while(hi>=lo)
        {
            int mid=(hi+lo)/2;
            if(t==nums[mid])
            {
                return mid;
            }
            else if(t<nums[mid])
            {
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        return -1;
    }
};
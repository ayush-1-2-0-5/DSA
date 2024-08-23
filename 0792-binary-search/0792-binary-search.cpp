class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int hi=n-1;
        int lo=0;

        while(hi>=lo)
        {
            int mid=(hi+lo)/2;
            if(target==nums[mid])
            return mid;

            else if(target<nums[mid])
            hi=mid-1;

            else if(target>nums[mid])
            lo=mid+1;

        }

        return -1;

    }
};
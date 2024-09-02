class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
       
   int n=nums.size();
if(n==1)
{
    return nums[0];
}
        int p=1;
        int s=1;
        for(int i=0;i<n;++i)
        {
            if(p==0)
            p=1;
            if(s==0)
            s=1;

            p=p*nums[i];
            s=s*nums[n-1-i];

            maxi=max(maxi,max(p,s));
        }

        return maxi;
    }
};
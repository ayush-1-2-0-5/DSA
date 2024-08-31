class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size();
        int ct=1;

        for(int i=1;i<n;++i)
        {
            if(nums[i]==ans)
            ct++;

          else if(ct<=0)
           {
            ans=nums[i];
             ct=1;
           }

           else 
           ct--;
        }
        return ans;
    }
};
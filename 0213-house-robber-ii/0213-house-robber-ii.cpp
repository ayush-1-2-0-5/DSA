class Solution {
public:
    int f(vector<int> nums)
    {
        
        int p1=nums[0];
        int p2=0;
        for(int i=1;i<nums.size();++i)
        {
           int t=nums[i];
           if(i>1)
           t+=p2;

           int nt=p1;

           int cur=max(t,nt);
           p2=p1;
           p1=cur;
           
        }

        return p1;
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
        int a=f(a1);
        int b=f(a2);

        return max(a,b);
    }
};

class Solution {
public:
         int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
   
    long long countPairs(vector<int>& nums, int k) {
        long long ans=0;
        map<int,int> mpp;

        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            int have=gcd(nums[i],k);
            int want=k/have;
             for(auto it: mpp)

             {
                  if(it.first%want==0)
                  ans+=it.second;
             }
             mpp[have]++;
        }
return ans;
    }
};
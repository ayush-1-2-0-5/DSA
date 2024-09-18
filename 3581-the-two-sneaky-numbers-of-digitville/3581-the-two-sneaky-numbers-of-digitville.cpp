class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
         int n=nums.size();

         vector<int> arr(n-2,0);

         for(auto i:nums)
         {
            arr[i]++;
         }

         for(int i=0;i<n-2;++i)
         {
            if(arr[i]==2)
            ans.push_back(i);
         }


return ans;
    }
};
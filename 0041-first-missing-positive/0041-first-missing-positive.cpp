class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
      int missno=1;
        for(auto i: nums)
        {
            if(i>0)
            {
             if(i==missno)
             {
                missno++;
             }
             else
             if(i>missno)
             {
                break;
             }
            }
        }
        return missno;
    }
};
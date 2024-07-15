class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();

        queue<int> q;
        int ct0=0;
        int i=0;
        int j=0;
        while(i<n)
        {
            if(nums[i]==0)
            {
                ct0++;
                q.push(i);
                if(ct0>k)
                {
                    j=q.front()+1;
                    q.pop();
                }
            
            }
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};
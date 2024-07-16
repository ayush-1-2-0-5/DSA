class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>> >  pq;

        int n=nums.size();
        int i=0;
        int maxi=INT_MIN;
        for(auto it: nums)
        {
            pq.push({it[0],{i,0}});    
            maxi=max(maxi,it[0]);
            i++;    
        }

        vector<int> ans(2);
        ans[0]=pq.top().first;
        ans[1]=maxi;
        int mini=pq.top().first;


        while(pq.size()==n)
        {
            int ele=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            if(c+1<nums[r].size())
            {
                pq.push({nums[r][c+1],{r,c+1}});
                maxi=max(maxi,nums[r][c+1]);
                mini=pq.top().first;

            }

            if(maxi-mini<ans[1]-ans[0])
            {
                  ans[1]=maxi;
                  ans[0]=mini;
            }


        }


        return ans;
    }
};
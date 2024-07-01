class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=0;
        int buy=prices[0];

        for(int i=1;i<prices.size();++i)
        {
            if(prices[i]<buy)
            buy=prices[i];

            else 
            mx=max(prices[i]-buy,mx);
        }

        return mx;
        
    }
};
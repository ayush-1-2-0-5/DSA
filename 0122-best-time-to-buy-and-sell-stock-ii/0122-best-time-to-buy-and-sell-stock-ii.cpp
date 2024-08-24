class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;

        for(int i=1;i<prices.size();++i)
        {
            if(prices[i-1]<prices[i])
            {
                maxi+=prices[i]-prices[i-1];
            }
        }
        return maxi;
    }
};
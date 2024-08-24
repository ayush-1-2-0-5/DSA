class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int maxi = 0;
        int buy = prices[0];
        
        for (int i = 1; i < prices.size(); ++i) {
          
            buy = min(buy, prices[i]);
            if (prices[i] > buy + fee) {
                maxi += prices[i] - buy - fee;
                buy = prices[i] - fee;
            }
        }
        
        return maxi;
    }
};

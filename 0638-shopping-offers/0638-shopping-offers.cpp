class Solution {
public:
    int uknapsack(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<string, int>& mpp) {
        int n = needs.size();
        string str = "";
        for (auto it : needs) {
            str += to_string(it) + ',';
        }

        int minp = 0;
        for (int i = 0; i < n; ++i) {
            minp += price[i] * needs[i];
        }
        
        if (mpp.find(str) != mpp.end()) {
            return mpp[str];
        }

        for (auto it : special) {
            bool flag = true;
            vector<int> newneed(n, 0);
            for (int i = 0; i < n; ++i) {
                if (it[i] > needs[i]) {
                    flag = false;
                    break;
                } else {
                    newneed[i] = needs[i] - it[i];
                }
            }

            if (flag) {
                minp = min(minp, it[n] + uknapsack(price, special, newneed, mpp));
            }
        }

        return mpp[str] = minp;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string, int> mpp;
        return uknapsack(price, special, needs, mpp);
    }
};
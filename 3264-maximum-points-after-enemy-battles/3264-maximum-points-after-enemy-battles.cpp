class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currE) {
        long long profit=0;
        int n=enemyEnergies.size();
        int j=n-1;

        sort(enemyEnergies.begin(),enemyEnergies.end());
        if(enemyEnergies[0]>currE)
        {
            return 0;
        }

        while(j>=0)
        {
            if(enemyEnergies[0]<=currE)
            {
                profit+=currE/enemyEnergies[0];
                currE%=enemyEnergies[0];

            }
            else
            {
                currE+=enemyEnergies[j];
                j--;
            }
        }

return profit;
    }
};
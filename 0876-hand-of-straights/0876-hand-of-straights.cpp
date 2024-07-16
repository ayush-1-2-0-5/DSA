class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0)
            return false;
        map<int, int> count;
        for (int card : hand)
            count[card]++;

        while (!count.empty()) {
            int start = count.begin()->first;  
            for (int j = 0; j < groupSize; ++j) {
                int current = start + j;
                if (count.find(current) == count.end())
                    return false; 
                if (--count[current] == 0)
                    count.erase(current);  
            }
        }

        return true;
    }
};

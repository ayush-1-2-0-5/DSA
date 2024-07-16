class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();

        if (n %k != 0)
            return false;
        map<int, int> count;
        for (int i : nums)
            count[i]++;

        while (!count.empty()) {
            int start = count.begin()->first;  
            for (int j = 0; j < k; ++j) {
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
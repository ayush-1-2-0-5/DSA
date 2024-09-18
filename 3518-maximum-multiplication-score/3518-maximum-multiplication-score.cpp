#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        if (a.size() < 4) return 0;
        
        vector<long long> ans(4, INT64_MIN);

        for (int i = 0; i < b.size(); ++i) {
            if (ans[2] != INT64_MIN) {
                ans[3] = max(ans[3], ans[2] + 1LL * a[3] * b[i]);
            }
            if (ans[1] != INT64_MIN) {
                ans[2] = max(ans[2], ans[1] + 1LL * a[2] * b[i]);
            }
            if (ans[0] != INT64_MIN) {
                ans[1] = max(ans[1], ans[0] + 1LL * a[1] * b[i]);
            }
            ans[0] = max(ans[0], 1LL * a[0] * b[i]);
        }

        return ans[3] == INT64_MIN ? 0 : ans[3];
    }
};

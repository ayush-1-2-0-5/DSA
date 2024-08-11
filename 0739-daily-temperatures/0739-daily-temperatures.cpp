class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int, int>> st;
        int n = t.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && st.top().first < t[i]) {
                int idx = st.top().second;
                ans[idx] = i - idx;
                st.pop();
            }
            st.push({t[i], i});
        }

        return ans;
    }
};

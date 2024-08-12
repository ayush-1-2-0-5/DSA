class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0); 
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }

        long long ans = 0;
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                int idx = st.top();
                st.pop();
                long long sum = pre[i] - pre[st.empty() ? 0 : st.top() + 1];
                ans = max(ans, sum * nums[idx]);
            }
            st.push(i);
        }

        return ans % 1000000007;
    }
};

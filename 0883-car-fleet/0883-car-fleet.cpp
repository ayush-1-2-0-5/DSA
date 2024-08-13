class Solution {
public:
    int carFleet(int t, vector<int>& p, vector<int>& s) {
        stack<double> st;
        vector<pair<int, int>> v;
        int n = p.size();
        
        for (int i = 0; i < n; ++i) {
            v.push_back({p[i], s[i]});
        }
        sort(v.begin(), v.end());
        
        for (int i = n - 1; i >= 0; --i) {
            auto it = v[i];
            int pos = it.first;
            int speed = it.second;
            double time = (double)(t - pos) / speed;
            
            if (!st.empty() && st.top() >= time) {
                continue;
            } else {
                st.push(time);
            }
        }
        
        return st.size();
    }
};

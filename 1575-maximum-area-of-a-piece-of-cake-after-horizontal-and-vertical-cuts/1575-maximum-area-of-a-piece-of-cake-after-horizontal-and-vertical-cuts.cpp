class Solution {
 public:
  int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
    constexpr int MOD = 1e9+7;
    ranges::sort(hc);
    ranges::sort(vc);

    int mx = max(vc[0], w - vc.back()), my = max(hc[0], h - hc.back());

    for (int i = 1; i < vc.size(); ++i) mx = max(mx, vc[i] - vc[i - 1]);
    for (int i = 1; i < hc.size(); ++i) my = max(my, hc[i] - hc[i - 1]);

    return static_cast<long>(mx) * my % MOD;
  }
};

#define ll long long
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define fr(a,b) for(int i = a; i < b; i++)
#define frn(a,b) for(int i = a; i >= b; i--)
#define frr(a,b,c) for(int i = a; i <= b &&c; i++)
#define frrn(a,b,c) for(int i = a; i >=b &&c; i--)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
class Solution {
public:
    long long maximumTotalSum(vector<int>& mxh) {
        long long ans = 0;
        sort(all(mxh), greater<int>());
        if (mxh[0] < mxh.size()) {
            return -1;  
        }

        int n = mxh.size();
        int prev = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (mxh[i] < prev) {
                ans += mxh[i];
                prev = mxh[i];
            } else {
                if (prev - 1 <= 0) {
                    return -1;  
                }
                ans += prev - 1;
                prev = prev - 1;
            }
        }

        return ans;
    }
};
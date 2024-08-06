#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define fr(a,b) for(int i = a; i < b; i++)
#define frn(a,b) for(int i = a; i >= b; i--)
#define frr(a,b,c) for(int i = a; i <= b && c; i++)
#define frrn(a,b,c) for(int i = a; i >= b && c; i--)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

class meetinmiddle {
private:
    int n;
    vvi left, right;
public:
    meetinmiddle(vi &nums) {
        n = nums.size() / 2; 
        left.resize(n + 1);
        right.resize(n + 1);
    }

    void print() {
        for(auto it: left) {
            for(auto i: it) {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
        for(auto it: right) {
            for(auto i: it) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    int calc(int x) {
        int ans = INT_MAX;
        for(int sz = 0; sz <= n; ++sz) {
            for(auto i: left[sz]) {
                int remain = (x - 2 * i) / 2;
                int remainsize = n - sz;
                auto &v = right[remainsize];
                auto itr = lower_bound(all(v), remain);

                if(itr != v.end()) {
                    ans = min(ans, abs(x - 2 * (i + (*itr))));
                }

                if(itr != v.begin()) {
                    auto it = itr;
                    --it;
                    ans = min(ans, abs(x - 2 * (i + (*it))));
                }
            }
        }
        return ans;
    }

    void algo(vi &nums) {
        int N = nums.size();
        int sum = accumulate(all(nums), 0);

        for(int msk = 0; msk < (1 << n); ++msk) {
            int sz = 0;
            int l = 0;
            int r = 0;
            for(int i = 0; i < n; ++i) {
                if(msk & (1 << i)) {
                    sz++;
                    l += nums[i];
                    r+=nums[i+n];
                }
              
            }
            left[sz].pb(l);
            right[sz].pb(r);
        }
        
        for(auto &v : right) {
            sort(all(v));
        }
    }
};



class Solution {
public:
   
    int minimumDifference(vector<int>& arr) {
      meetinmiddle mm(arr);

      mm.algo(arr);
      int sum=accumulate(all(arr),0);

      int ans=mm.calc(sum);

      return ans;       
    }
};

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
   int fun(int a)
   
   {
    int ans=0;
    while(a>0)
    {
        ans+=a%10;
        a=a/10;
    }
    return ans;
   }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(auto it:  nums)
        {
            mini=min(mini,fun(it));
        }

        return mini;
    }
};
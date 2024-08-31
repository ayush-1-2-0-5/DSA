#include<bits/stdc++.h>
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
    string stringHash(string s, int k) {
        int n = s.length();
        int times= n / k;
        string res = "";

        for (int i = 0; i < times; ++i) {
            string temp = s.substr(i * k, k);
            int sum = 0;
            for (char ch : temp) {
                sum += (ch - 'a'); 
            }
            int hash = sum % 26;
        
            char charr = 'a' + hash;
            res +=charr;
        }

        return res;
    }
};
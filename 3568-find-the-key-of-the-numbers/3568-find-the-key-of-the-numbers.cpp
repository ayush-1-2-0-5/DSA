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
    int generateKey(int num1, int num2, int num3) {
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        string s3 = to_string(num3);
             s1 = string(4 - s1.length(), '0') + s1;
           s2 = string(4 - s2.length(), '0') + s2;
            s3 = string(4 - s3.length(), '0') + s3;
        string key;
        for (int i = 0; i < 4; ++i) {
            char d1 = s1[i];
                char d2 = s2[i];
            char d3 = s3[i];
            char mini = min(d1, min(d2, d3));
            key += mini;
        }
        int result = stoi(key);
        return result;
    }
};




















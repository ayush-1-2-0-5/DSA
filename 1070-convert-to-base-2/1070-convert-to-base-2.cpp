class Solution {
public:
    string baseNeg2(int n) {
        string ans;

    while (n != 0) {
      ans += to_string(n & 1);
      n = -(n >> 1);
      cout<<n<<endl;
    }
    

    return ans.empty() ? "0" : string{ans.rbegin(), ans.rend()};
    }
};
class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.length();
        string res = "";
        k = k % n;  


        res = s.substr(k) + s.substr(0, k);

        return res;
    }
};

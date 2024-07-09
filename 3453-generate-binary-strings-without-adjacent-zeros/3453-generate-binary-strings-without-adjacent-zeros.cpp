#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void backtrack(int n, bool dig0, vector<string> &ans, string &temp) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        temp += '1';
        backtrack(n, false, ans, temp);
        temp.pop_back();
        if (!dig0) {
            temp += '0';
            backtrack(n, true, ans, temp);
            temp.pop_back();
        }
    }
     
    vector<string> validStrings(int n) {
        vector<string> ans;
        string temp = "";
        backtrack(n, false, ans, temp);  
        return ans;
    }
};

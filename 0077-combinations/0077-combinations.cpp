class Solution {
public:
 void backtrack(vector<vector<int>> &ans, vector<int> &temp, int start, int n, int k) {
    if (k == 0) {
        ans.push_back(temp);
        return;
    }

    for (int i = start; i <= n - k + 1; ++i) {
        temp.push_back(i);
        backtrack(ans, temp, i + 1, n, k - 1);
        temp.pop_back();
    }
}


    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans,temp,1,n,k);
        return ans;
    }
};
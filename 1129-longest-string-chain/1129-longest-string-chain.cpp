class Solution {
public:
    bool match(string str1, string str2) {
        if (str1.size() != str2.size() + 1) return false;
        
        int i = 0, j = 0;
        while (i < str1.size()) {
            if (j < str2.size() && str1[i] == str2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        
        return j == str2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);
        int answer = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (match(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            answer = max(answer, dp[i]);
        }
        return answer;
    }
};

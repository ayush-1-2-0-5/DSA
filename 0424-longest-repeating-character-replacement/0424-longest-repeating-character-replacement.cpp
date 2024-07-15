class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26, 0);
        int ans = 0;
        int i = 0;
        int j = 0;
        int n = s.length();
        int maxf = 0;

        while (i < n) {
            hash[s[i] - 'A']++;
            maxf = max(maxf, hash[s[i] - 'A']);

            while (i - j + 1 - maxf > k) {
                hash[s[j] - 'A']--;
                j++;
            }

            ans = max(ans, i - j + 1);
            i++;
        }

        return ans;
    }
};

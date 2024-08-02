class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        stringstream ss1(s1), ss2(s2);
        string w;
        while (ss1 >> w) {
            freq[w]++;
        }

        while (ss2 >> w) {
            freq[w]++;
        }

        vector<string> answer;
        for (auto& [k, v] : freq) {
            if (v == 1) {
                answer.push_back(k);
            }
        }

        return answer;
    }
};
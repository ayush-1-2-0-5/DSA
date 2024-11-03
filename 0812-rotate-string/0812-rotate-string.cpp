class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
    }
};

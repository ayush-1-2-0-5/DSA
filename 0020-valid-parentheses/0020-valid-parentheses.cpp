class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> mp = {{')', '('}, {']', '['}, {'}', '{'}};

        for (auto i : s) {
            if (i == '(' || i == '[' || i == '{') {
                st.push(i);
            } else {
                if (st.empty() || st.top() != mp[i]) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty(); 
    }
};
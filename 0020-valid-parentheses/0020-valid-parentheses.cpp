class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
          map<char, char> mp = {{')', '('}, {']', '['}, {'}', '{'}};
        for(auto it: s)
        {
            if(it=='('||it=='{'||it=='[')
            st.push(it);

            else
            {
                if(mp[it]!=st.top())
                return false;
                else
                st.pop();
            }
        }
        return st.empty();
    }
};
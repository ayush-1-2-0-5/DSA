class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto it: tokens) {
            string s = it;
            if(s != "+" && s != "*" && s != "-" && s != "/") {
                int a = stoi(s);  
                st.push(a);
            }
            else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(s == "+") {
                    st.push(b + a);  
                }
                else if(s == "-") {
                    st.push(b - a);  
                }
                else if(s == "*") {
                    st.push(b * a);  
                }
                else if(s == "/") {
                    st.push(b / a);  
                }
            }
        }
        return st.top();
    }
};

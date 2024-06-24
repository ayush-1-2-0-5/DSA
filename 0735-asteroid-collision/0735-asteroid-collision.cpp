class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int ast : asteroids) {
            bool exploded = false;
            while (!st.empty() && st.top() > 0 && ast < 0) {
                if (st.top() < -ast) {
                    st.pop();
                } else if (st.top() == -ast) {
                    st.pop(); 
                    exploded = true;
                    break;
                } else {
                    exploded = true;
                    break;
                }
            }
            if (!exploded) {
                st.push(ast);
            }
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};

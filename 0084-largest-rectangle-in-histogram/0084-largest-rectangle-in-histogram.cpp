class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int mxA=0;
      int n=heights.size();

      for(int i=0;i<=n;++i)
      {
        while(!st.empty() && (i==n||heights[st.top()]>=heights[i]))
        {
            int ht=heights[st.top()];
            // cout<<ht<<" "<<"ht after "<<i<<" iteration"<<endl;
            st.pop();
            int width;
            if(st.empty())
            width=i;
            else
            width=i-st.top()-1;
            mxA=max(mxA,ht*width);
            //  cout<<mxA<<" " << ht*width<<" "<<"mxa after "<<i<<" iteration"<<endl;


        }
        st.push(i);
        // cout<<i<<" "<<"elein st"<<endl;
      }
        return mxA;
    }
};
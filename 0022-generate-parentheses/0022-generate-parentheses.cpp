class Solution {
public:
      void fun(int open,int close, vector<string> &ans ,int n,string s)
      {
          if(open==close && open==n)
          {
              ans.push_back(s);
          }
          if(open<n)
          {
              fun(open+1,close,ans,n,s+"(");
          }
          if(close<open)
          {
              fun(open,close+1,ans,n,s+")");
          }
          
      }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fun(0,0,ans,n,"");

        return ans;

    }
};

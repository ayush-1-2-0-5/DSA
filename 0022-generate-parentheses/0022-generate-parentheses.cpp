class Solution {
public:
    void solve(int open,int close,vector<string>&ans,int n,string temp)
    {
        if(open==close&& open==n )
        {
          ans.push_back(temp);
          return;
        }
        if(open<n)
        {
            solve(open+1,close,ans,n,temp+"(");
        }
        if (close<open)
        {
            solve(open,close+1,ans,n,temp+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0,0,ans,n,"");
        return ans;
    }
};
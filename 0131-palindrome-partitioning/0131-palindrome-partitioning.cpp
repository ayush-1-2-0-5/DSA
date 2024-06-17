class Solution {
public:
    bool ispalindrome(string s)
    {
        int i=0;
        int j=s.length()-1;

        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }

    void backtrack(vector<vector<string>> &ans,vector<string> &temp,int idx,string s)
    {
        if(idx==s.length())
        {
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<s.length();++i)
        {
            string t=s.substr(idx,i-idx+1);
            if(ispalindrome(t))
            {
                temp.push_back(t);
                backtrack(ans,temp,i+1,s);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        backtrack(ans,temp,0,s);

        return ans;
    }
};

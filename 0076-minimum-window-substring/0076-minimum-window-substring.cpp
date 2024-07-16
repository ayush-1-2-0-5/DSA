class Solution {
public:
    string minWindow(string s, string t) {
       int l=0;
       int r=0;
       int ans=INT_MAX;
       int n=s.length();
       int len=t.length();
       int sidx=-1;
       int hash[256];
       for(auto i: t)
       {
        hash[i]++;
       }
       int ct=0;
       while(r<n)
       {
        if(hash[s[r]]>0) ct++;
        hash[s[r]]--;

        while(ct==len)
        {
            if(r-l+1<ans)
            {
            ans=min(ans,r-l+1);
            sidx=l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0)ct--;
            l++;
        }

        r++;
       }
       return sidx==-1?"":s.substr(sidx,ans);
    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> hash(3,-1);
        int r=0;
        int n=s.length();
       int ans=0;
        while(r<n)
        {
            hash[s[r]-'a']=r;
            if(hash[0]!=-1 && hash[1]!=-1 &&  hash[2]!=-1)
            {
               int mini=min({hash[0],hash[1],hash[2]});
               ans+=1+mini;
            } 
            r++;
        }
        return ans;
    }
};
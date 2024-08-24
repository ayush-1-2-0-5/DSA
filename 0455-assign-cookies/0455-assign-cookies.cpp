class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int ct=0;
          int i=0;
          int j=0;
          int n=g.size();
          int m=s.size();

          while(i<n && j<m)
          {
              if(g[i]<=s[j])
              {
                ct++;
                i++;
                j++;
              }
              else
              j++;
          }
        
        return ct;
    }
};
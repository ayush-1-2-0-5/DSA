class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors ) {
        int ct=0;
       if(colors.size()<3)return 0;

        for(int i=0;i<3;++i)
        {
            colors.push_back(colors[i]);
        }

        int n=colors.size();

        vector<int> v(n,0);
        for(int i=0;i<n;++i)
        {
            if(colors[i]==colors[(i+1)%n])
            v[i]=1;
        }

        for(int i=1;i<n;++i)
        {
            v[i]+=v[i-1];
        }

       for(int i=0;i<n-3;++i)
       {
           int j=i+3-1;
            if((v[j]-v[i])==0)
            ct++;


      }


return ct;
        


    }
};
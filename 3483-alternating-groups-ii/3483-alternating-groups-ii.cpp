class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors ,int k) {
        int ct=0;
       if(colors.size()<k)return 0;

        for(int i=0;i<k;++i)
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

       for(int i=0;i<n-k;++i)
       {
           int j=i+k-1;
            if((v[j]-v[i])==0)
            ct++;


      }


return ct;
        


    }
};
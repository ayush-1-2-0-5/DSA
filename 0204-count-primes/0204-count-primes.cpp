class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
        return 0;
      vector<bool> composites(n,false);

int limit=(int)sqrt(n);


      for(int i=2;i<=limit;++i)
      {
        if(composites[i]==false)
        {
            for(long long j=i*i;j<n;j+=i)
            {
               composites[j]=true;
            }
        }
      }

      int ct=0;
      for(int i=2;i<n;++i)
      {
        if(composites[i]==false)
        ct++;
      }

      return ct;
    }
};
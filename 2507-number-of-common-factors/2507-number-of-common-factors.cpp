
class Solution {
public:
    int commonFactors(int a, int b) {
        int ct = 0;
        int d = min(a, b);

        for (int i = 1; i*i <= d; ++i) {
            if (d%i==0)
            {
                int f=i;
                int sf=d/i;
                 if(f==sf)
                 {
                    if(a%i==0 && b%i==0)
                    ct++;
                 }
                 else
                 {
                       if(a%i==0 && b%i==0)
                    ct++;
                       if(a%sf==0 && b%sf==0)
                    ct++;
                 }
            }
        }
        return ct;
    }
};

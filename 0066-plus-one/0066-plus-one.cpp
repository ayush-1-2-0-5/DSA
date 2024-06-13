class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1]!=9)
        {
            digits[n-1]++;
            return digits;
        }
        int a=0;
        for(int i=n-1;i>=0;--i)
        {
             if(digits[i]==9)
             {
                a=i;
                digits[i]=0;
             }
             else 
             {
                digits[i]++;
                break;
             }
        }
       if(a==0)
       {
        digits.insert(digits.begin(),1);
       }
        return digits;
    }
};
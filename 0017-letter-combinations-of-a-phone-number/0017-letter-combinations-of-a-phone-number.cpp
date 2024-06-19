class Solution {
public:

void mylettercomb(string digits,vector<string> &res, string nums[],int i, string s)
    {
        if(i==digits.length())
        {
            res.push_back(s);
            return;
        }

        string val=nums[digits[i]-'0'];
        for(int j=0;j<val.length();++j)
        {
            mylettercomb(digits,res,nums,i+1,s+val[j]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
        {
            return ans;
        }
        string nums[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        mylettercomb(digits,ans,nums,0,"");
        return ans;

};
};
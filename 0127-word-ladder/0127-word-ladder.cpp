class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        set<string> s;
        int k=beginWord.length();

        for(auto it: wordList)
        {
            s.insert(it);
        }

        q.push({beginWord,1});
     int ans=0;
        while(!q.empty())
        {
            int l=q.front().second;
            string b=q.front().first;
            if(b==endWord)
            {
            return l;
            }
            q.pop();

            for(int i=0;i<k;++i)
            {
                char origchar=b[i];
                for(char ch='a';ch<='z';++ch)
                {
                    b[i]=ch;
                    if(s.find(b)!=s.end())
                    {
                        q.push({b,l+1});
                       
                    }
                     s.erase(b);
                    
                    b[i]=origchar;
        
                }

            }

        }
       return 0; 
    }
};
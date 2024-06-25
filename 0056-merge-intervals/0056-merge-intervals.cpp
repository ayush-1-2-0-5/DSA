class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        int n=intervals.size();
      sort(intervals.begin(),intervals.end());
      vector<int> temp=intervals[0];

      for(int i=0;i<n;++i)
      {
           auto it=intervals[i];
           if(temp[1]>=it[0])
           {
             temp[1]=max(temp[1],it[1]);
           }

           else 
           {
              merged.push_back(temp);
              temp=it;
           }
      }
      merged.push_back(temp);
      return merged;
    }
};
struct Node {
   Node* links[2]; 
   bool containsKey(int bit) {
       return (links[bit] != NULL); 
   }
   Node* get(int bit) {
       return links[bit]; 
   }
   void put(int bit, Node* node) {
       links[bit] = node; 
   }
};

class Trie {
private:
   Node* root;
public:
   Trie() {
       root = new Node();
   }
   void insert(int num) {
       Node* node = root;
       for (int i = 31; i >= 0; i--) {
           int bit = (num >> i) & 1;
           if (!node->containsKey(bit)) {
               node->put(bit, new Node());
           }
           node = node->get(bit);
       }
   }
   int getMax(int num) {
       Node* node = root;
       int maxNum = 0;
       for (int i = 31; i >= 0; i--) {
           int bit = (num >> i) & 1;
           if (node->containsKey(1 - bit)) {
               maxNum |= (1 << i);
               node = node->get(1 - bit);
           } else {
               node = node->get(bit);
           }
       }
       return maxNum;
   }
};



class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
       int n=queries.size();
        vector<int> ans(n);
        Trie trie;
vector<pair<int, pair<int,int>>> Queries;
    sort(nums.begin(), nums.end());
      int index = 0;
    for(auto &it: queries) {
        Queries.push_back({it[1],{it[0], index++}}); 
    }
    sort(Queries.begin(),Queries.end());

     int a= nums.size(); 
       int i=0;

       for(auto it: Queries)
       {
      while(i < a && nums[i] <= it.first) {
        trie.insert(nums[i]); 
        i++; 
    }
    
    if(i != 0) 
        ans[it.second.second] = trie.getMax(it.second.first); 
    else 
        ans[it.second.second] = -1;   
       }
       return ans;
    }
};
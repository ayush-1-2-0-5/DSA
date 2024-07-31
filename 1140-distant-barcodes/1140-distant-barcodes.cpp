class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        vector<int> answer(n);
        priority_queue<pair<int,int>> pq;

        map<int,int> mpp;

        for(auto i: barcodes) {
            mpp[i]++;
        }

        for(auto it: mpp) {
            pq.push({it.second, it.first});
        }

        int i = 0;
        while(!pq.empty()) {
            auto itr = pq.top();
            pq.pop();
            for(int j = 0; j < itr.first; ++j) {
                if(i >= n) i = 1; 
                answer[i] = itr.second;
                i += 2;
            }
        }

        return answer;
    }
};
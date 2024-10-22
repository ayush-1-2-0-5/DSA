
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            long long levelSum = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            pq.push(levelSum);
            if (pq.size() > k) {
                pq.pop();  
            }
        }
        if (pq.size() < k) return -1;
        return pq.top();
    }
};
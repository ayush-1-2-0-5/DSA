class Solution {
public:
    void bfs(TreeNode* root, vector<vector<int>>& ans) {
        if (!root)
            return;

        queue<TreeNode*> q;
        q.push(root);
        bool reverseLevel = false; 

        while (!q.empty()) {
            int size = q.size();
            vector<int> levelNodes(size);

            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                int index = reverseLevel ? size - i - 1 : i;
                levelNodes[index] = curr->val;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            reverseLevel = !reverseLevel;
            ans.push_back(levelNodes);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bfs(root, ans);
        return ans;
    }
};
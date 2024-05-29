class Solution {
public:
  int check(TreeNode*root){
    if(root==nullptr)
    return 0;
    int lh=check(root->left);
    int rh=check(root->right);
    if(lh==-1 || rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return 1+max(lh,rh);
  }
    bool isBalanced(TreeNode* root) {
        int c=check(root);
        return c>=0?true:false;
    }
};
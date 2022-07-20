vector<string> binaryTreePaths(TreeNode *root){
  vector<string> ans;
  if(!root)return false;
  helper(root,ans,to_string(root->val));
}

void helper(TreeNode *root,ans,string s){
  if(!root->left && root->right){
    ans.push_back(s);
    return;
  }
  if(root->left) helper(root->left,ans,s+"->"+to_string(root->left->val));
  if(root->right) helper(root->right,ans,s+"->"+to_string(root->right->val));
}
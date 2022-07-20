vector<int> pathtoNode(TreeNode * root , int b){
  vector<int> ans;
  if(!root)return ans;
  helper(root,ans,b);
  return ans;
}
bool helper(TreeNode *root,vector<int> &ans,int b){
  if(root==NULL)
  return false;
  ans.push_back(node->val);
  if(node->val == b)
  return true;
  if(helper(root->left,ans,b) || helper(root->right,ans,b))
  return true;
  ans.pop_back();
  return false;
}
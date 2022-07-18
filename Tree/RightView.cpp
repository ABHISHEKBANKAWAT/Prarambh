void helper(TreeNode * root,int level,vector<int> &ans){
  if(root==NULL)
    return;
  if(ans.size()==level)
  {
    ans.push_back(root->level);
  }
  helper(root->right,level+1,ans);
  helper(root->left,level+1,ans);
}

vector<int> rightSideView(TreeNode *root)
{
  vector<int> ans;
  int level = 0;
  helper(root, ans, level);
  return ans;
}

//for left view
void helper(TreeNode *root, int level, vector<int> &ans)
{
  if (root == NULL)
    return;
  if (ans.size() == level)
  {
    ans.push_back(root->level);
  }
  helper(root->left, level + 1, ans);
  helper(root->right, level + 1, ans);
}
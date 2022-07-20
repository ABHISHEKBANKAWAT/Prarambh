TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
  if (root == NULL)
  {
    return NULL;
  }
  TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
  TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);
  if (root->val == p->val || root->val == q->val)
    return root;
  if (leftAns != NULL && rightAns != NULL)
  {
    return root;
  }
  if (leftAns != NULL)
    return leftAns;
  if (rightAns != NULL)
    return rightAns;
  return NULL;
}
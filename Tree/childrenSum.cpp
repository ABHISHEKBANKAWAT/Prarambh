int fun(BinaryTreeNode<int> *root, int par)
{
  if (!root)
    return 0;
  int l = fun(root->left, max(root->data, par));
  int r = fun(root->right, max(root->data, par));
  root->data = max(l + r, max(root->data, par));
  return root->data;
}

void changeTree(BinaryTreeNode<int> *root)
{
  fun(root, 0);
}
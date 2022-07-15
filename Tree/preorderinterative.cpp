vector<int> preorderTraversal(TreeNode *root){
  vector<int> preorder;
  stack<TreeNode*> st;
  if(root==NULL) return preorder;
  st.push(root);
  while(!st.empty()){
    root = st.top();
    st.pop();
    preorder.push_back(root->val);
    if(root->right) st.push(root->right);
    if(root->left) st.push(root->left);
  }
  return preorder;
}
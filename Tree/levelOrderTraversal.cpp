vector<vector<int>> levelOrderTraversal(TreeNode * root){
  vector<vector<int>> ans;
  if(root==NULL)return NULL;
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty()){
    int size = q.size();
    vector<int> level;
    for(int i = 0 ; i< size;i++){
    TreeNode * node = q.front();
    q.pop();
    level.push_back(node->data);
    if(node->left!=NULL) q.push(node->left);
    if(node->right!=NULL) q.push(node->right);
  }
  ans.push_back(level);
}
return ans;
}
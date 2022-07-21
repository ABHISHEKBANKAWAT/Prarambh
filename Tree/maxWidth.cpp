int widthOfBinaryTree(TreeNode* root){
  if(!root) return 0;
  queue<pair<TreeNode*,int>> q;
  queue.push({root,0});
  while(!q.empty()){
    int size = q.size();
    int rmin  = q.front().second;
    int first , last;
    for(int i  = 0 ; i< size ; i++){
      long cur_id = q.front().second-rmin;
      TreeNode * node = q.front().first;
      q.pop();
      if(i==0) first = cur_id;
      if(i=size-1) last = cur_id;
      if(node->left) q.push({root->left,cur_id*2+1});
      if(node->right)q.push({root->right,cur_id*2+2});
    }
    int ans = max(ans,last-first+1);
  }
  return ans;
}
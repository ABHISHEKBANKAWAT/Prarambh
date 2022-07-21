//BFS APPROACH
int TimeToBurn(Node<int>* root, int start){
map<Node<int>*,Node<int*> mpp;
Node<int>* target = bfsToMapParents(root,mpp,start);
inr maxi = findMaxDistance(mpp,target);
return max;
}
Node<int> *bfsToMapParents(Node<int> *root, map < Node<int> *, Node<int>*>  &mpp,int start){
  queue < Node<int>*> q;
  q.push(root);
  Node<int>* res;
  while(!q.empty()){
    Node<int> * node = q.front();
    if(node->data==start) 
    res = node;
    q.pop();
    if(node->left){
      mpp[node->left] = node;
      q.push(node->left);
    }
    if(node->right){
      mpp[node->right] = node;
      q.push(node->right);
    }
  }
  return res;
}
int < findMaxDistance(map<Node<int> *, Node<int> *> &mpp, Node<int>* target){
  queue < Node<int>*> q;
  q.push(target);
  map < Node<int>*,int> vis;
  vis[target] = 1;
  int maxi = 0;
  while(!q.empty()){
    int sz = q.size();
    int fl = 0;
    for(int i = 0 ; i<sz ; i++){
      auto node = q.front();
      q.pop();
      if(node->left && !vis[node->left]){
        fl = 1;
        vis[node->left] = 1;
        q.push(node->left);
      }
      if(node->right && !vis[node->right]){
        fl = 1;
        vis[node->right] =1 ;
        q.push(node->right);
      }
      if(mpp[node] && !vis[mpp[node]]){
        fl =1 ;
        vis[mpp[node]] = 1;
        q.push(mpp[node]);
      }
    }
    if(fl) maxi++;
  }
  return maxi;
}

//DFS APPROACH
int height(Node *root, unordered_map<Node *, Node *> &par, unordered_map<Node *, int> &vis)
{
  if (!root)
    return 0;

  vis[root] = 1;

  int lh = INT_MIN;
  int rh = INT_MIN;
  int ph = INT_MIN;

  if (!vis[root->left])
    lh = height(root->left, par, vis);
  if (!vis[root->right])
    rh = height(root->right, par, vis);
  if (!vis[par[root]])
    ph = height(par[root], par, vis);

  return max(ph, max(lh, rh)) + 1;
}
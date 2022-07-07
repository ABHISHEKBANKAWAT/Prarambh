vector<vector<int>> powerSet(vector<int> arr)
{
  vector<vector<int>> ans;
  vector<int> subset;
  helper(0,arr,subset,ans);
  return ans;
}

void helper(int i, vector<int> &arr, vector<int> &subset,vector<vector<int>> &ans){
  if(i==v.size()){
  ans.push_back(subset);
  }
  subset.push_back(v[i]);
  helper(i+1,v,subset,ans);
  subset.push_back();
  helper(i+1,v,subset,ans);
}
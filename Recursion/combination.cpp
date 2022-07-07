// Summarization : 
// 1. Generate all subsets and add size of k into the ans 
// 2. discard all the subsets more than size of k 
// 3. skip the combinations which may not have chance to get of k elements.

void helper(int i,int n,int k,vector<int> &subset,vector<vector<int>> &ans)
{ 
  if(k==0){
  ans.push_back(subset);
}
//elements size greater than
if(n>k)return;
//remaining elements are smaller than k
if(k>n-i+1)return;
  //taking up
  subset.push_back(i);
  helper(i+1,n,k-1,subset,ans);
  //skip part 
  subset.pop_back();
  helper(i+1,n,k,subset,ans);
}

vector<vector<int>> combine(int n, int k) {
vector<int> subset;
vector<vector<int>> ans;
helper(1,n,k,subset,ans);
}

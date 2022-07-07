// Combination sum I
// 1)Here,we need to generate all the subset in that those sum will be equal to expected sum so for that we are using sum variable to keep track of sum of all elements inside subset
// 2) Here when we are picking an element there is a chance that we can pick the same element again in future so we are not incrementing i and wen we aren't picking we are incrementing i and we are incrementing sum while calling recursive function
// 3) Time Complexity :- 0(2 pow n) and  Space Complexity:-0(n)

void helper(int i,int target,int sumtillnow,vector<int> &v,vector<int> &subset,vector<vector<int>> &ans)
{
  if(sumtillnow == target)
  {
    ans.push_back(subset);
    return;
  }
  if(sumtillnow>target) return;
  if(i>=v.size()) return;
  //taking the element
  sumtillnow += v[i];
  subset.push_back(v[i]);
  helper(i,target,sumtillnow,v,subset,ans);
  subset.pop_back();
  sumtillnow -= v[i];
  //skiping the element
  helper(i+1,target,sumtillnow,v,subset,ans);

}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
  vector<int> subset;
  vector<vector<int>> ans;
  int sumtillnow = 0;
  helper(0,target,sumtillnow,candidates,subset,ans);
  return ans;
}
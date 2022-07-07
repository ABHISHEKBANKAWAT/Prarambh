void helper(int i,vector<int> &nums,vector<int> &subset,vector<vector<int>> &ans)
{
  if(i==nums.size())
  {
    ans.push_back(subset);
    return;
  }
  subset.push_back(nums[i]);
  helper(i+1,nums,subset,ans);
  subset.pop_back();
  while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
  helper(i+1,nums,subset,ans);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{ sort(nums.begin(),nums.end());
  vector<int> subset;
  vector<vector<int>> ans;
  helper(0,nums,subset,nums);
  return ans;
}
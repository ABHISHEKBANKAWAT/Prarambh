vector<vector<int>> permute(vector<int> &nums)
{
  vector<vector<int>> ans;
  helper(0,nums,ans);
  return ans;
}
void helper(int pos, vector<int> &nums, vector<vector<int>> &ans)
{  if(pos>=nums.size())
{
  ans.push_back(nums);
}
  for(int i = pos;i<nums.size();i++)
  {
    swap(nums[i],nums[pos]);
    helper(pos+1,nums,ans);
    swap(nums[i],nums[pos]);
  }
}
vector<vector<int>> permute(vector<int> &nums){
  vector<vector<int>> ans;
  helper(0,nums,ans);
  return ans;
}
void helper(int pos,vector<int> &nums,vector<vector<int>> &ans)
{ if(pos>=nums.size())
{
  ans.push_back(nums);
  return;
} unordered_set<int> m;
  for(int i = pos;i<nums.size();i++)
  if(m.find(nums[i])!=m.end()) continue;
  m.insert(nums[i]);
  swap(nums[i],nums[pos]);
  helper(pos+1,nums,ans);
  swap(nums[i],nums[pos]);
}
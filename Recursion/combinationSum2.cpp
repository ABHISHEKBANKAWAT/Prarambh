// Summary:
// 1. Combination Sum 2 is a question of Subsets-II, which was generating Unique subsets, and Combination- I where we need to generate a subsets whose sum is equal to TargetSum. To avoid duplicate elements, we need to sort the given array first then only we can use the logic as we discussed previously of generating Unique subsets with duplicate elements.
// 2. The only difference is that we can't keep choosing an element as many times as we want. We can choose an element only once.
// 3. So what we will do here is, we use the knowledge of Subsets-II and Combination Sum -1 to solve the question.
// 4. The bases cases are very simple:
// a) if(currenrSum == targetSum)
// put the subset in your ans[][] vector and return.
// b) if (currentSum > targetSum)
// We can't get the targetSum, so we should return
// c) if(i >= arr.size()) 
// We have traversed the entire array so we should return.
// 5)We then pick the ith element, put it into our subset[] vector and increment sum as sum += arr[i] and call Recursive function with i+1
// 6) On returning, we need to backtrack, and put the element out of subset vector and bring currentSum to its original value.
// 7) Now to avoid duplicate elements, we start traversing through the subset till arr[i] == arr[i+1]
// 8)After that, we apply the condition of don't pick, so i+1 but currentSum remains the same.
// Time Complexity: O(2^N) [ Because we are always moving to the next index so it can be O(2^N) , if target is equal to sum of all array elements as well]
// Space Complexity: O(N) [ It's equal to the height of the Recursive tree, so it's O(N)]

void helper(int i, int target, int sumtillnow, vector<int> &v, vector<int> &subset, vector<vector<int>> &ans)
{
  if (sumtillnow == target)
  {
    ans.push_back(subset);
    return;
  }
  if (sumtillnow > target)
    return;
  if (i >= v.size())
    return;
  sumtillnow += v[i];
  subset.push_back(v[i]);
  helper(i + 1, target, sumtillnow, v, subset, ans);
  sumtillnow -= v[i];
  subset.pop_back();
  while (i + 1 < v.size() && v[i] == v[i + 1])
    i++;
  helper(i + 1, target, sumtillnow, v, subset, ans);
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
  sort(candidates.begin(), candidates.end());
  vector<int> subset;
  vector<vector<int>> ans;
  helper(0, target, 0, candidates, subset, ans);
  return ans;
}
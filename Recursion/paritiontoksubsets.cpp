// Logic:
// 1)if sum of list is not divisible by k then we can not construct k subsets from the list whose sum is equal
// 2)Even though the sum of list is divisible by k we may or may not get k subsets whose sum is equal
// 3)Subset sum is constructed by totalListSum // k

// for every element in the array which is not used have two choices either to go into the current bucket or not
// if it goes into the bucket mark the alreadyPicked array index as used and update the bucketSum, then ask the recursion to do for the remaining elements.

// if it does not goes to the bucket then ask the recursion to do for the next element

// if the bucketSum == reqSum then we have successfully constructed the current bucket so go fill the next bucket

// if bucketNum >= required subsets then return True as all the previous buckets are able to fill with reqSum

// if bucketSUM > reqSum or i >= len(array) return False
#include <bits/stdc++.h>
using namespace std;

bool help(int i, int bucketNum, int bucketSum, int reqSum, int K, vector<int> &nums, vector<int> &alreadyPicked)
{
  if (bucketNum == K + 1)
    return true;
  if (bucketSum == reqSum)
  {
    return help(0, bucketNum + 1, 0, reqSum, K, nums, alreadyPicked);
  }

  if (bucketSum > reqSum)
    return false;
  if (i >= nums.size())
    return false;
  if (alreadyPicked[i] == 1)
  {
    return help(i + 1, bucketNum, bucketSum, reqSum, K, nums, alreadyPicked);
  }
  else
  {
    bucketSum += nums[i];
    alreadyPicked[i] = 1;
    bool op1 = help(i + 1, bucketNum, bucketSum, reqSum, K, nums, alreadyPicked);

    bucketSum -= nums[i];
    alreadyPicked[i] = 0;
    bool op2 = help(i + 1, bucketNum, bucketSum, reqSum, K, nums, alreadyPicked);

    return op1 | op2;
  }
}

bool canPartitionKSubsets(vector<int> &nums, int n, int K)
{
  // Write your code here.
  vector<int> alreadyPicked(n, 0);
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += nums[i];
  if (sum % K != 0)
    return false;
  int reqSum = sum / K;
  return help(0, 1, 0, reqSum, K, nums, alreadyPicked);
}
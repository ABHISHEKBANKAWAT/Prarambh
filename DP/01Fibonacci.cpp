// STEP1   Create a dp[n+1] array initialized to -1.
// STEP2   Whenever we want to find the answer of a particular value (say n), we first check whether the answer is already calculated using the dp array(i.e dp[n]!= -1 ). If yes, simply return the value from the dp array.
// STEP3   If not, then we are finding the answer for the given value for the first time, we will use the recursive relation as usual but before returning from the function, we will set dp[n] to the solution we get.
// the two common dynamic programming approaches are :

//  Memoization : Known as the “top - down” dynamic programming,usually the problem is solved in the direction of the main problem to the base cases.
//  Tabulation : Known as the “bottom - up ” dynamic programming, usually the problem is solved in the direction of solving the base cases to the main problem

//Memoization for fibonacci series
#include<bits/stdc++.h>
using namespace std;
// int fib(int n,vector<int> &dp){
//   if(n<=1){
//     return 1;
//     if(dp[n]!=-1) return dp[n];
//     return dp[n] = fib(n-1,dp) + fib(n-2,dp); 
//   }
// }
// int main()
// {

//   int n = 5;
//   vector<int> dp(n + 1, -1);
//   cout << fib(n, dp);
//   return 0;
// }

//Tabualation

int main()
{

  int n = 5;
  vector<int> dp(n + 1, -1);

  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  cout << dp[n];
  return 0;
}
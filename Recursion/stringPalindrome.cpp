//to check if String is Palindrome

bool palindrome(String S)
{
  return helper(0,S.size(),S);
}
bool helper(int l , int r, Stirng &S)
{
  if(l>=r) return true;
  if(S[l]!=S[r]) return false;
  helper(l+1,r-1,S);
}
// Summary:
// 1. This question uses all the concepts of subsets and combinations we have studied so far.
// 2. In this problem, we need to generate all the words possible from the number of keypad given by the user as input
// 3. To solve this problem, we firstly need a unordered_map to map all the keypad characters like '2' , '3' , '4' , etc with the letters they represent in the keypad phone. This can be done using unordered_map or vector using its indices
// 4. Now we need to create a function help which takes the given string s, ans vector to store all the answers, i to iterate over given string and a temp string to store the current word we are making. Everything is passed by reference to save space. 
// 5. If i reaches to s.size(), it means we have traversed the entire string, so we put the temp word inside the ans vector and return.
// 6. Else we would pick a string str = map[s[i]] . This will represent all the letters represented by i-th character of string s. 
// 7. We run a for loop for j = 0 till j < str.size() and we add str[j] character inside our temp string and ask Recursion to solve for i+1th character.
// 8. After Recursion gives me the answer, we have to backtrack and pop the character we have included so that other characters of string str can now take its place.
// 10. Lastly, we return ans vector from our given function.

// Time complexity: O(3^N) [ As most of the letters has 3 choices so we can approximately say time complexity as 3^N]

// Space Complexity: O(N) [ N is the size of the given string. This is because we can only process till i < s.size() , that's why Space Complexity is O(N)]
void helper(int i,string &s,string &temp,vector<string> ans,unordered_map<char,string> &m)
{
  if(i==s.size()){
    ans.push_back(temp);
    return;
  }
  string str = m[s[i]];
  for(int j = 0 ; j<str.size();j++){
    temp.push_back(str[i]);
    helper(i+1,s,temp,ans,m);
    temp.pop_back();
  }
}
vector<string> letterCombinations(string digits)
{
  if(digits.size()==0){
    return;
  }
  unordered_map<char,string> m;
  m['2'] = "abc";
  m['3'] = "def";
  m['4'] = "ghi";
  m['5'] = "jkl";
  m['6'] = "mno";
  m['7'] = "pqrs";
  m['8'] = "tuv";
  m['9'] = "wxyz";
  vector<string> ans;
  string temp;
  helper(0,digits,temp,ans,m);
  return ans;
}
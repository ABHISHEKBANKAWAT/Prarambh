// Summary:
// 1. In this question, we have to find the maximum length of the string which we can find using all the strings present in arr vector. We are not bothered about the string we form but only about the maximum length. The only criteria is that the string formed shouldn't have repeating characters. 
// 2. To know the string doesn't have repeating characters, we need to use a selected vector which will tell us whether one character has been previously selected or not. 
// 3. If a character is previously selected, we will simply ignore that string. Also if a string itself has repeating characters we can't include it inside our final answer string. 
// 4. To check if the string has repeating characters or if the string has some characters from previously used strings, we need to use a bool compare() function which returns true if the string has unique characters and no overlapping characters with any other taken string. Else returns false 
// 5. The base case is very simple-
// if( i >= arr.size() )
// We have traversed through the entire vector of strings so we should return the length of the valid string collected so far 
// 6. Else we will first check whether we could include currString= arr[i] into our final answer or not using compare() function
// 7. If currString is not valid, we simply move i to the next index
// 8. Else we pick currString so we need to mark all the characters of currString as present inside selected vector, increment len by currString.size() and call for i+1
// 9. And now if we don't currString, we backtrack and unmark all it's characters, decrement len by currString.size() and check for i+1
// 10. Lastly we return the max of pick and don't pick. 

// Time Complexity: O(k * 2^N) [If k is the average length of string present in vector arr and for every string we are either picking it or not picking it that's why,  I think, Time Complexity is O(k* 2^N)
// Space Complexity: O(N) [ As we are traversing through the entire arr vector so height of the tree is O(N). Also we will not count the spaces of selected vectors because they are always of 26 size so we don't need to consider their sizes as they are independent of N]

bool compare(vector<int> &selected, string &currString)
{
  vector<int> selfCheck(26, 0);
  for (int i = 0; i < currString.size(); i++)
  {
    if (selfCheck[currString[i] - 'a'] == 1)
      return false;
    selfCheck[currString[i] - 'a'] = 1;
  }

  for (int i = 0; i < currString.size(); i++)
  {
    if (selected[currString[i] - 'a'] == 1)
      return false;
  }
  return true;
}

int help(int i, vector<string> &arr, vector<int> &selected, int len)
{

  if (i == arr.size())
  {
    return len;
  }
  string currString = arr[i];
  if (!compare(selected, currString))
  {
    return help(i + 1, arr, selected, len);
  }
  else
  {
    for (int j = 0; j < currString.size(); j++)
    {
      selected[currString[j] - 'a'] = 1;
    }
    len += currString.size();
    int op1 = help(i + 1, arr, selected, len);

    for (int j = 0; j < currString.size(); j++)
    {
      selected[currString[j] - 'a'] = 0;
    }

    len -= currString.size();
    int op2 = help(i + 1, arr, selected, len);

    return max(op1, op2);
  }
}

int stringConcatenation(vector<string> &arr)
{
  // Write your code here
  vector<int> selected(26, 0);
  return help(0, arr, selected, 0);
}
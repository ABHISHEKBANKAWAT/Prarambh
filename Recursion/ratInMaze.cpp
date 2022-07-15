// // Rat In a Maze we can use recusrion to find all the paths in a grid 
// As we can go in all 4 directions DOWN , UP , RIGHT , LEFT
// Algorithm:
// 1.We will check if the direction in which we are going is valid or not 
// 2.Else if the we are at final position (n-1,m-1) we will add it to the Ans
// 3.Else We will go  in all 4 directons and keep a check if the position is already visited or not
// 4.then In backtracking we will pop the direction and make the position again unvisited;

//this is for n*n grid
void helper(int i,int j,int n,vector<vector<int>> &arr,string &path,vector<string> &ans)
{
  if(i<0 || j<0 || i==n || j==n || arr[i][j] ==0 ) return;
  else if(i==n-1 && j == n-1){
    ans.push_back(path);
    return;
  }
  else{
    arr[i][j] = 0;
    // DOWN
    path.push_back('D');
    helper(i-1,j,n,arr,path,ans);
    path.pop_back();

    // LEFT
    path.push_back('L');
    helper(i, j-1,n, arr, path, ans);
    path.pop_back();
    // RIGHT
    path.push_back('R');
    helper(i, j+1,n, arr, path, ans);
    path.pop_back();
    // UP
    path.push_back('U');
    helper(i+1,j,n,arr,path,ans);
    path.pop_back();

    arr[i][j] = 1;
  }
}
vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
  string path;
  vector<string> ans;
  helper(0,0,n,arr,path,ans);
  return ans;
  
}

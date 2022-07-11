// Flood Fill algorithm is a simple Recursive question.

//     1. In this problem,
//     we need to change the old color of a cell, starting from(x, y), with the newColor given in the question.We should only colour those cells which have the old colour and not any other cell.And we should always be within the boundaries of the grid.2. One edge case will be if newColor == oldColor.In that case, we don't need to change anything simply return the 2D image vector 3. If not we will use recursion to color all the cells having oldColor with newColor.4. Base cases will be pretty simple.We need to stay within the boundaries of the grid and we should change only those grids who have oldColor.if (i < 0 || i >= m || j < 0 || j >= n || image[i][j] != oldColor) return;
// 5. Now we need to move on 4 directions - up, down, left, right and ask recursion to color all the remaining cells having color as oldColor.
//  Time Complexity : O(M *N)[In worst case, we need to traverse the entire grid because all the cells might be having oldColor] Space Complexity : O(M *N)[In worst case we start from(0, 0) and pain the entire grid with newColor.This causes the recursive stack space equal to O(M * N)]

void helper(int i, int j, vector<vector<int>> &image, int oldcolor, int newcolor, int m, int n)
{
  if (i < 0 || j < 0 || i == n || j == m || image[i][j] != oldcolor)
    return;
  image[i][j] = newcolor;
  helper(i + 1, j, image, oldcolor, newcolor, m, n);
  helper(i - 1, j, image, oldcolor, newcolor, m, n);
  helper(i, j + 1, image, oldcolor, newcolor, m, n);
  helper(i, j - 1, image, oldcolor, newcolor, m, n);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
  int oldcolor = image[sr][sc];
  int n = image.size();
  int m = image[0].size();
  if (oldcolor == color)
    return image;
  helper(sr, sc, image, oldcolor, color, m, n);
  return image;
}
  
// 1. We need to place N Queens in N*N chessboard. That means we can only place only one Queen in every row. We cannot skip any row else we cannot solve it. We need to return all possible solutions by placing queens in different positions throughout the chessboard.
// 2. Queens can cancel each other - in same row , in same column, in left diagonal(both up and down) and in right diagonal(up and down). However, as we are placing 1 Queen in every row so we don't need to check for rows. Also, as we are filling our chessboard in up to down manner , we don't need to check for down Left Diagonal and Down Right Diagonal respectively,
// 3. Instead of checking everytime in the column or Upper Left or Right Diagonal respectively, we can use 3 separate arrays/vectors of length n to check if placing a queen at (i,j) in the board is safe or not. The mapping goes as follows:
// a) for columns: a simple array where cols[i] = 1 if Queen is placed else cols[i] = 0 is sufficient.
// b) for Upper Right Diagonal: we map using (row + col) with index of UpperRight vector, that is, in our Upper Right Diagonal array UpperLeft[currentRow + currentCol] = 1 if Queen is present in the Upper Right Diagonal of (currentRow, currentCol) else it will be 0.
// c) for Upper Left Diagonal: we map(row - col + n - 1) with index of UpperLeft vector. If Queen is present UpperLeft[i] = 1 else it will e 0.

// 4. Now our task is pretty easy. If our row == n, it means we have successfully placed all N-Queens in the chessboard, so we save our current configuration of the board in our vector<vector<int>> and and return back.
// 5. Otherwise, we will iterate over all the columns from 0 till n-1 using a for loop and see where we can place a Queen in currentRow or i-th row.
// 6. For check we will declare a isSafe() function which takes currentRow , currentCol, cols[] , UpperLeft[] and UpperRight[] vectors. Or we can simply iterate over all the columns of currentRow , and check the diagonals as well. Whichever suits us better we can use it.
// 7. Lastly, whenever isSafe() returns true, we will place the Queen at that location and ask recursion to place rest of the Queens starting from next Row thatis, currentRow + 1.
// 8. At the end, we return our and[][] from the given function, which contains all possible N-Queens solutions.

// Time Complexity: O(N!) [ As Fraz sir has explained, at first row we are having N choices, in the next row, we will be having (N-1) choices and in the next to next row, we will be having (N-2) choices at max ... which roughly calculates to N! ways. So Time Complexity is O(N!)

// Space Complexity: O(N) [ Only recursive stack space] & O(N^2) [if we consider our vector<vector<int>> and containing all valid configurations] {
//   The Height of recursive tree will only be equal to N(number of Queens) but if we consider all the our and[][] vector containing all valid configurations then our Space Complexity is O(N ^ 2).Generally, we always consider the Auxiallary Stack Space or any other data structures we use by our own but it's always better to explain all the complexities to the Interviewer !!

vector<vector<string>> solveNQueens(int n){

}
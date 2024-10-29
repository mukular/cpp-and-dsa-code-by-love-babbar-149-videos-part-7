/*
Q.1. The N Queens puzzle is the problem of placing N chess queens on an N * N chessboard 
such that no two queens attack each other.
Given an integer ‘N’, print all distinct solutions to the ‘N’ queen puzzle.

Two queens on the same chessboard can attack each other if any of the below condition satisfies:  
1. They share a row. 
2. They share a column. 
3. They share a diagonal. 

Sample Input 1:
1
4   
Sample Output 1:
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
Explanation for Sample Input 1:
The 4 queens can be placed in two ways in a 4*4 chessboard. Both the configurations are shown in the below figure. 

The chessboard matrix for the first configuration looks as follows:-
0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0
Queen contained cell is depicted by 1. As we can see, No queen is in the same row, column 
or diagonal of the other queens. Hence this is a valid configuration.

Similarly, the chessboard matrix for the second configuration looks as follows:-
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
Queen contained cell is depicted by 1. As we can see, No queen is in the same row, column 
or diagonal of the other queens. Hence this is also a valid configuration.

These are the only two valid configurations for 4-Queens. 
Sample Input 2:
1
3
Sample Output 2:
Explanation of Sample Input 2:
Since no possible configuration exists for 3 Queen's, the output remains empty. 

*/

/*
// Solution of question 1:-
// Time Complexity = O(n!)
// Space Complexity = O(n*n)

void addSolution(vector<vector<int> > &ans, vector<vector<int> > &board, int n)
{
    vector<int> temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int> > &board, int n)
{
    int x = row;
    int y = col;

    // check for same row
    while(y >= 0)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    x = row;
    y = col;
    // check for diagnol
    while(x >= 0 && y >= 0)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        y--;
        x--;
    }

    x = row;
    y = col;
    while(x < n && y >= 0)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        y--;
        x++;
    }

    return true;
}

void solve(int col, vector<vector<int> > &ans, vector<vector<int> > &board, int n)
{
    if(col == n)
    {
        addSolution(ans, board, n);
        return;
    }

    for(int row = 0; row < n; row++)
    {
        if(isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            solve(col+1, ans, board, n);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int> > board(n, vector<int>(n, 0));
    vector<vector<int> > ans;

    solve(0, ans, board, n);

    return ans; 
	
}
*/
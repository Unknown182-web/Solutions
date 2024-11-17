
#include <iostream.h>
#include <conio.h>  
#define MAX 20  
void printSolution(int board[MAX][MAX], int N) {
    for (int i = 0; i < N; ++i) {
for (int j = 0; j < N; ++j) {
if (board[i][j]) {
cout << "Q ";           
   } else {
cout << ". ";  
}
}
cout << endl;
}
    cout << endl;
}
int isSafe(int board[MAX][MAX], int row, int col, int N) {
    for (int i = 0; i < row; ++i) {
if (board[i][col]) {
return 0;
	}
    }
    int j;
    for (i= row,j=col; i >= 0 && j >= 0; --i, --j) {
	if (board[i][j]) {
	    return 0;
	}
    }
    for (i = row, j = col; i >= 0 && j < N; --i, ++j) {
	if (board[i][j]) {
	    return 0;
	}
    }

    return 1; 
}

int solveNQueens(int board[MAX][MAX], int row, int N) {
    if (row >= N) {
	return 1;      }

    for (int i = 0; i < N; ++i) {
	if (isSafe(board, row, i, N)) {
	    board[row][i] = 1;  

	    if (solveNQueens(board, row + 1, N)) {
		return 1;  	    }

	    board[row][i] = 0;  	}
    }

    return 0;
}

void main() {
    clrscr();

    int N;
    int board[MAX][MAX] = {0}; 
    cout << "Enter the number of queens (N): ";
    cin >> N;

    if (N <= 0 || N > MAX) {
	cout << "Invalid number of queens. Please enter a value between 1 and " << MAX << ".\n";
	return;
    }

    if (solveNQueens(board, 0, N)) {
	cout << "Solution:\n";
	printSolution(board, N);
    } else {
	cout << "No solution exists for " << N << " queens.\n";
    }

    getch();

}
/* C/C++ program to solve N Queen Problem using
backtracking */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > result;

/* A utility function to check if a queen can
be placed on board[row][col]. Note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool isSafe(vector<vector<int> > board, int row, int col){
	int i, j;
	int N = board.size();

	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

/* A recursive utility function to solve N Queen problem */
bool solveNQUtil(vector<vector<int> >& board, int col){

	int N = board.size();
	if (col == N) {
		vector<int> v;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 1)
					v.push_back(j + 1);
			}
		}
		result.push_back(v);
		return true;
	}

	bool res = false;
	for (int i = 0; i < N; i++) {
		if (isSafe(board, i, col)) {
			board[i][col] = 1;

			res = solveNQUtil(board, col + 1) || res;

			board[i][col] = 0; // BACKTRACK
		}
	}

	return res;
}

/* This function solves the N Queen problem using Backtracking. It mainly uses solveNQUtil() to solve the problem. 
It returns false if queens cannot be placed, otherwise return true and prints placement of queens in the form of 1s.
Please note that there may be more than one solutions, this function prints one of the feasible solutions.*/

vector<vector<int> > nQueen(int n){
	result.clear();
	vector<vector<int> > board(n, vector<int>(n, 0));

	if (solveNQUtil(board, 0) == false) 
		return {};

	sort(result.begin(), result.end());
	return result;
}

int main(){
	int n = 4;
	vector<vector<int> > v = nQueen(n);

	for (auto ar : v) {
		cout << "[";
		for (auto it : ar)
			cout << it << " ";
		cout << "]";
	}

	return 0;
}
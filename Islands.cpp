#include <vector>
#include <iostream>
using namespace std;

int numIslands(vector<vector<char>>& grid);
void dfs(vector<vector<char>> &, int, int);


int main()
{
	vector<vector<char>> grid1 = {{'1', '0', '0'},{'0', '1', '0'},{'0', '0', '1'}}; 
	
	cout << "There are " << numIslands(grid1) << " islands." << endl;

	return 0;
}

int numIslands(vector<vector<char>> &grid)
{
	if (grid.empty()) return 0;

	int islands = 0;
	const int ROWS = grid.size();
	const int COLS = grid[0].size();

	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			if (grid[r][c] == '1') {
				dfs(grid, r, c);
				islands += 1;
			}
		}
	}

	return islands;
}

void dfs(vector<vector<char>> &grid, int r, int c)
{
	const int ROWS = grid.size();
	const int COLS = grid[0].size();

	if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] != '1') return;

	grid[r][c] = '0';

	dfs(grid, r + 1, c);
	dfs(grid, r - 1, c);
	dfs(grid, r, c + 1);
	dfs(grid, r, c - 1);
}

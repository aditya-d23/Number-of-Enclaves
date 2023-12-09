#include<iostream>
#include<vector>
using namespace std;
void dfs(int row,int col, vector<vector<int>>& grid, vector<vector<int>> &vis,int n,int m,int delrw[],int delcl[]) {
	vis[row][col] = 1;
	for (int i = 0; i < 4; i++) {
		int nRow = row + delrw[i];
		int nCol = col + delcl[i];
		if (nRow >= 0 and nRow < n and nCol >= 0 and nCol < m and !vis[nRow][nCol] and grid[nRow][nCol]) {
			dfs(nRow, nCol, grid, vis, n, m, delrw, delcl);
		}
	}
}
int numEnclaves(vector<vector<int>>& grid) {
	int n = grid.size();
	int m = grid[0].size();
	int delrw[] = { 0,-1,0,1 };
	int delcl[] = { -1,0,1,0 };
	vector<vector<int>> vis(n, vector<int>(m, 0));
	//first row
	for (int i = 0; i < n; i++) {
		if (!vis[0][i] and grid[0][i] == 1)
			dfs(0, i, grid, vis, n, m, delrw, delcl);
	}
	//last row
	for (int i = 0; i < n; i++) {
		if (!vis[n - 1][i] and grid[n - 1][i] == 1)
			dfs(n-1, i, grid, vis, n, m, delrw, delcl);
	}
	//first column
	for (int i = 0; i < m; i++) {
		if (!vis[i][0] and grid[i][0] == 1) {
			dfs(i, 0, grid, vis, n, m, delrw, delcl);
		}
	}
	//last column
	for (int i = 0; i < m; i++) {
		if (!vis[i][m - 1] and grid[i][m - 1] == 1) {
			dfs(i, m-1, grid, vis, n, m, delrw, delcl);
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == 0 and grid[i][j] == 1) {
				count++;
			}
		}
	}
	return count;
}

int main() {
	vector<vector<int>> grid = { {0, 0, 0, 0 }, 
								 {1, 0, 1, 0},
								 {0, 1, 1, 0},
								 {0, 0, 0, 0}
                                               };

	cout<<numEnclaves(grid);
}
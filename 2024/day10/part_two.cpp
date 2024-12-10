#include <bits/stdc++.h>
using namespace std;

int dfs(const vector<string> &grid, int i, int j, vector<vector<int>> &visited) {
    if (grid[i][j] == '0')
        return visited[i][j] = 1;
    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            if (di == dj || di == -dj)
                continue;
            if (0 <= i + di && i + di < grid.size() && 0 <= j + dj && j + dj < grid[0].size() &&
                grid[i + di][j + dj] == grid[i][j] - 1) {
                if (visited[i + di][j + dj])
                    visited[i][j] += visited[i + di][j + dj];
                else
                    visited[i][j] += dfs(grid, i + di, j + dj, visited);
            }
        }
    }
    return visited[i][j];
}

int main() {
    vector<string> grid;
    string t;
    while (cin >> t)
        grid.push_back(t);
    int n = grid.size(), m = grid[0].size();

    int ans = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '9') {
                fill(visited.begin(), visited.end(), vector<int>(m, 0));
                ans += dfs(grid, i, j, visited);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

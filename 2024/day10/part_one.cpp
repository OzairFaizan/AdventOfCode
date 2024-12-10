#include <bits/stdc++.h>
using namespace std;

int dfs(const vector<string> &grid, int i, int j, vector<vector<bool>> &visited) {
    visited[i][j] = true;
    if (grid[i][j] == '9')
        return 1;
    int ans = 0;
    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            if (di == dj || di == -dj)
                continue;
            if (0 <= i + di && i + di < grid.size() && 0 <= j + dj && j + dj < grid[0].size() &&
                grid[i + di][j + dj] == grid[i][j] + 1 && !visited[i + di][j + dj])
                ans += dfs(grid, i + di, j + dj, visited);
        }
    }
    return ans;
}

int main() {
    vector<string> grid;
    string t;
    while (cin >> t)
        grid.push_back(t);
    int n = grid.size(), m = grid[0].size();

    int ans = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '0') {
                fill(visited.begin(), visited.end(), vector<bool>(m, false));
                ans += dfs(grid, i, j, visited);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

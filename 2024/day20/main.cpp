#include <bits/stdc++.h>
using namespace std;

bool inside(int i, int j, int n, int m) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs(int i, int j, int t, const vector<string> &grid, vector<vector<int>> &visited) {
    visited[i][j] = t;
    for (auto dir : vector<pair<int, int>> { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }) {
        int ni = i + dir.first, nj = j + dir.second;
        if (inside(ni, nj, grid.size(), grid[0].size()) &&
                grid[ni][nj] != '#' && visited[ni][nj] == INT_MAX) {
            dfs(ni, nj, t+1, grid, visited);
        }
    }
}

int main() {
    int time = 20, min_gain = 100;
    vector<string> grid;
    string s;
    while (cin >> s) grid.push_back(s);
    int n = grid.size(), m = grid[0].size();

    int si, sj, ei, ej;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') si = i, sj = j;
            if (grid[i][j] == 'E') ei = i, ej = j;
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
    dfs(si, sj, 0, grid, visited);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') continue;
            for (int di = -time; di <= time; ++di) {
                for (int dj = abs(di) - time; dj <= time - abs(di); ++dj) {
                    int ni = i + di, nj = j + dj;
                    ans += inside(ni, nj, n, m) && grid[ni][nj] != '#' &&
                        visited[i][j] - visited[ni][nj] >= min_gain + abs(di) + abs(dj);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}

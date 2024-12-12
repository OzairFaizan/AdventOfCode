#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int area_perimeter(int si, int sj, const char c, const vector<string> &grid,
                   vector<vector<bool>> &visited) {
    int n = grid.size(), m = grid[0].size();
    auto in_closure = [&](int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m && grid[i][j] == c;
    };

    int area = 0, perimeter = 0;
    queue<pair<int, int>> queue;
    queue.push({si, sj});
    while (!queue.empty()) {
        auto ij = queue.front();
        queue.pop();
        if (visited[ij.first][ij.second]) {
            continue;
        }
        visited[ij.first][ij.second] = true;

        int neighbours = 0;
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                if (di == dj || di == -dj)
                    continue;
                int i = ij.first + di, j = ij.second + dj;
                if (in_closure(i, j)) {
                    if (!visited[i][j])
                        queue.push({i, j});
                    ++neighbours;
                }
            }
        }
        ++area;
        perimeter += (4 - neighbours);
    }

    return area * perimeter;
}

int main() {
    vector<string> grid;
    string s;
    while (cin >> s)
        grid.push_back(s);

    ll ans = 0;
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!visited[i][j])
                ans += area_perimeter(i, j, grid[i][j], grid, visited);
    cout << ans << endl;
    return 0;
}

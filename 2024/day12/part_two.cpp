#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int area_sides(int si, int sj, const char c, const vector<string> &grid,
               vector<vector<bool>> &visited) {
    int n = grid.size(), m = grid[0].size();
    auto in_closure = [&](int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m && grid[i][j] == c;
    };

    int area = 0, sides = 0;
    set<pair<int, int>> pos;
    queue<pair<int, int>> queue;
    queue.push({si, sj});
    pos.insert({si, sj});
    while (!queue.empty()) {
        auto ij = queue.front();
        queue.pop();
        int i = ij.first, j = ij.second;
        if (visited[i][j]) {
            continue;
        }
        visited[i][j] = true;
        ++area;

        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                if (di == dj || di == -dj)
                    continue;
                int row = i + di, col = j + dj;
                if (in_closure(row, col) && !visited[row][col]) {
                    queue.push({row, col});
                    pos.insert({row, col});
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool top = false;
            while (!in_closure(i - 1, j) && pos.count({i, j})) {
                top = true;
                ++j;
            }
            sides += top;
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            bool right = false;
            while (!in_closure(i, j + 1) && pos.count({i, j})) {
                right = true;
                ++i;
            }
            sides += right;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool bottom = false;
            while (!in_closure(i + 1, j) && pos.count({i, j})) {
                bottom = true;
                ++j;
            }
            sides += bottom;
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            bool left = false;
            while (!in_closure(i, j - 1) && pos.count({i, j})) {
                left = true;
                ++i;
            }
            sides += left;
        }
    }

    return area * sides;
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
                ans += area_sides(i, j, grid[i][j], grid, visited);
    cout << ans << endl;
    return 0;
}

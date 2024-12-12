#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int, int> area_perimeter_sides (int si, int sj, const char c, const vector<string> &grid,
                   vector<vector<bool>> &visited) {
    int n = grid.size();
    auto in_closure = [&](int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < n && grid[i][j] == c;
    };

    int area = 0, perimeter = 0, sides = 0;
    set<pair<int, int>> pos;
    queue<pair<int, int>> queue;
    queue.push({si, sj});
    while (!queue.empty()) {
        auto [i, j] = queue.front();
        pos.insert({i, j});
        queue.pop();
        if (visited[i][j])
            continue;
        visited[i][j] = true;

        int neighbours = 0;
        for (auto [di, dj] : vector<pair<int, int>>{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}) {
            int col = i + di, row = j + dj;
            if (in_closure(col, row)) {
                if (!visited[col][row])
                    queue.push({col, row});
                ++neighbours;
            }
        }
        ++area;
        perimeter += (4 - neighbours);
    }

    for (int i = 0; i < n; ++i) {
        bool top = true, bottom = true, left = true, right = true;
        for (int j = 0; j < n; ++j) {
            if (pos.count({i, j}))
                sides += (!in_closure(i - 1, j) && top) + (!in_closure(i + 1, j) && bottom),
                    top = in_closure(i - 1, j), bottom = in_closure(i + 1, j);
            else
                top = true, bottom = true;

            if (pos.count({j, i}))
                sides += (!in_closure(j, i - 1) && left) + (!in_closure(j, i + 1) && right),
                    left = in_closure(j, i - 1), right = in_closure(j, i + 1);
            else
                right = true, left = true;
        }
    }

    return {area * perimeter, area * sides};
}

int main() {
    vector<string> grid;
    string s;
    while (cin >> s)
        grid.push_back(s);

    ll ans = 0;
    int n = grid.size();
    assert(grid.size() == grid[0].size());
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!visited[i][j])
                ans += area_perimeter_sides(i, j, grid[i][j], grid, visited).second;
    cout << ans << endl;
    return 0;
}

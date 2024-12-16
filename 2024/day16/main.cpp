#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<string> grid;
    string s;
    while (cin >> s) grid.push_back(s);
    int n = grid.size(), m = grid[0].size();
    vector<pair<int, int>> dirs = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
    int si, sj, ei, ej;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') si = i, sj = j;
            if (grid[i][j] == 'E') ei = i, ej = j;
        }
    }

    // {-cost, dir, i, j}
    priority_queue<tuple<int, int, int, int>> q; q.push({0, 3, si, sj});
    vector<vector<int>> cost(n, vector<int>(m, INT_MAX)); cost[si][sj] = 0;
    while(!q.empty()) {
        auto [ncost, dir, i, j] = q.top(); q.pop();
        for (auto d : {dir, (dir + 1) % 4, (dir + 3) % 4}) {
            int ni = i + dirs[d].first, nj = j + dirs[d].second;
            int nc = 1000 * (d != dir) + 1 - ncost;
            if (grid[ni][nj] != '#' && cost[ni][nj] > nc) {
                q.push({-nc, d, ni, nj});
                cost[ni][nj] = nc;
            }
        }
    }
    cout << "Part one: " << cost[ei][ej] << endl;

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> qu; qu.push({ei, ej});
    while(!qu.empty()) {
        auto [i, j] = qu.front(); qu.pop();
        visited[i][j] = true;
        for (auto d : dirs) {
            int pi = i - d.first, pj = j - d.second;
            int ni = i + d.first, nj = j + d.second;
            if (cost[i][j] == cost[ni][nj] + 1 || cost[i][j] == cost[ni][nj] + 1001 || 
                (visited[pi][pj] && cost[pi][pj] == cost[ni][nj] + 2)) {
                qu.push({ni, nj});
            }
        }
    }
    int ans = 0;
    for (auto l : visited) for (bool b : l) ans += b;
    cout << "Part two: " << ans << endl;

    return 0;
}

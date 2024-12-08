#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> grid;
    string in;
    while (cin >> in) {
        grid.push_back(in);
    }
    int n = grid.size(), m = grid[0].size();

    set<char> antinodes;
    unordered_map<char, vector<pair<int, int>>> antinodes_pos;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '.') {
                antinodes.insert(grid[i][j]);
                antinodes_pos[grid[i][j]].push_back({i, j});
            }
        }
    }

    vector<vector<bool>> overlaps(n, vector<bool>(m, false));
    for (char antinode : antinodes) {
        auto positions = antinodes_pos[antinode];
        for (int i = 0; i < positions.size(); ++i) {
            for (int j = i + 1; j < positions.size(); ++j) {
                int di = positions[i].first - positions[j].first;
                int dj = positions[i].second - positions[j].second;
                pair<int, int> overlap1 = {positions[i].first, positions[i].second};
                while (0 <= overlap1.first && overlap1.first < n && 0 <= overlap1.second &&
                       overlap1.second < m) {
                    overlaps[overlap1.first][overlap1.second] = true;
                    overlap1 = {overlap1.first + di, overlap1.second + dj};
                }
                pair<int, int> overlap2 = {positions[j].first, positions[j].second};
                while (0 <= overlap2.first && overlap2.first < n && 0 <= overlap2.second &&
                       overlap2.second < m) {
                    overlaps[overlap2.first][overlap2.second] = true;
                    overlap2 = {overlap2.first - di, overlap2.second - dj};
                }
            }
        }
    }

    int ans = 0;
    for (auto l : overlaps) {
        for (bool b : l)
            ans += b;
    }
    cout << ans << endl;
    return 0;
}

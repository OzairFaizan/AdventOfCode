#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int, int> mtod(char m) {
    switch (m) {
        case '<': return {0, -1};
        case '^': return {-1, 0};
        case '>': return {0, 1};
        case 'v': return {1, 0};
    }
    return {0, 0};
}

int main() {
    vector<string> grid;
    string moves = "";
    bool is_grid = true;
    string s;
    while (cin >> s) {
        if (is_grid && s[0] != '#') is_grid = false;
        if (is_grid) grid.push_back(s);
        else moves += s;
    }
    int n = grid.size(), m = grid[0].size();

    int si, sj;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] == '@')
                si = i, sj = j, grid[si][sj] = '.';

    for (char move : moves) {
        auto [di, dj] = mtod(move);
        int ni = si + di, nj = sj + dj;
        if (grid[ni][nj] == '.') {
            si = ni, sj = nj;
            continue;
        }
        vector<pair<int, int>> to_push;
        while (grid[ni][nj] == 'O') {
            to_push.push_back({ni, nj});
            ni += di, nj += dj;
        }
        if (grid[ni][nj] == '#') continue;
        auto [fi, fj] = to_push[0];
        grid[fi][fj] = '.';
        auto [li, lj] = to_push[to_push.size()-1];
        grid[li+di][lj+dj] = 'O';
        si = fi, sj = fj;
    }


    ll ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] == 'O')
                ans += 100 * i + j;
    cout << ans << endl;
    return 0;
}

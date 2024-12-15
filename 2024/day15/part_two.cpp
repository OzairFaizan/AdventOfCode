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

void print_grid(vector<string> &g) {
    for (auto s : g) {
        cout << s << endl;
    }
    cout << endl;
}

int main() {
    vector<string> grid;
    string moves = "";
    bool is_grid = true;
    string s;
    while (cin >> s) {
        if (is_grid && s[0] != '#') is_grid = false;
        if (!is_grid) moves += s;
        else {
            string ss = "";
            for (char c : s) {
                if (c == '#')      ss += "##";
                else if (c == '.') ss += "..";
                else if (c == '@') ss += "@.";
                else if (c == 'O') ss += "[]";
            }
            grid.push_back(ss);
        }
    }
    int n = grid.size(), m = grid[0].size();

    int si, sj;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] == '@')
                si = i, sj = j, grid[si][sj] = '.';

    for (char m : moves) {
        auto [di, dj] = mtod(m);
        int ni = si + di, nj = sj + dj;
        if (grid[ni][nj] == '.') {
            si = ni, sj = nj;
            continue;
        }

        bool possible = true;
        set<pair<int, int>> seen;
        vector<pair<int, int>> to_push = {{si, sj}};
        for (int i = 0; i < to_push.size(); ++i) {
            auto [mi, mj] = to_push[i];
            mi += di, mj += dj;
            if (grid[mi][mj] == '[') {
                if (!seen.count({mi, mj}))
                    to_push.push_back({mi, mj});
                if (!seen.count({mi, mj+1}))
                    to_push.push_back({mi, mj+1});
                seen.insert({mi, mj});
                seen.insert({mi, mj+1});
            } else if (grid[mi][mj] == ']') {
                if (!seen.count({mi, mj}))
                    to_push.push_back({mi, mj});
                if (!seen.count({mi, mj-1}))
                    to_push.push_back({mi, mj-1});
                seen.insert({mi, mj});
                seen.insert({mi, mj-1});
            } else {
                if (grid[mi][mj] == '#') {
                    possible = false;
                    break;
                }
            }
        }

        if (!possible) continue;
        for (int i = to_push.size() - 1; i > 0; --i) {
            auto [fi, fj] = to_push[i];
            grid[fi+di][fj+dj] = grid[fi][fj];
            grid[fi][fj] = '.';
        }
        si = to_push[1].first, sj = to_push[1].second;
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] == '[')
                ans += 100 * i + j;
    cout << ans << endl;
    return 0;
}

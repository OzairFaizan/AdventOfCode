#include <bits/stdc++.h>
using namespace std;
#define SIZE 71


int bfs(vector<vector<bool>> &g) {
    auto reachable = [&](int i, int j, int t) {
        return 0 <= i && i < SIZE && 0 <= j && j < SIZE && g[i][j];
    };

    queue<tuple<int, int, int>> q; q.push({0, 0, 0});
    set<pair<int, int>> pushed;
    while (!q.empty()) {
        auto [i, j, t] = q.front(); q.pop();
        if (i == SIZE-1 && j == SIZE-1) {
            return t;
        }
        for (auto [di, dj] : vector<pair<int, int>> {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
            if (reachable(i+di, j+dj, t+1) && !pushed.count({i+di, j+dj})) {
                q.push({i+di, j+dj, t+1});
                pushed.insert({i+di, j+dj});
            }
        }
    }
    return -1;
}


void part_one() {
    vector<vector<bool>> g(SIZE, vector<bool>(SIZE, true));
    for (int t = 1; t <= 1024; ++t) {
        int i, j; cin >> j >> i;
        g[i][j] = false;
    }
    cout << "Part one: " << bfs(g) << endl;
}


void part_two() {
    int i, j;
    vector<vector<bool>> g(SIZE, vector<bool>(SIZE, true));
    for (int t = 1; cin >> j >> i; ++t) {
        g[i][j] = false;
        if (bfs(g) == -1) {
            cout << "Part two: " << j << ',' << i << endl;
            return;
        }
    }
}


int main() {
    /*part_one();*/
    part_two();
    return 0;
}

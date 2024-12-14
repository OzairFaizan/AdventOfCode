#include <bits/stdc++.h>
using namespace std;

#define WIDTH 101
#define HEIGHT 103

inline int mod(int a, int n) {
    return ((a % n) + n) % n;
}

#define LONGLINE 20
// reddit.com/r/adventofcode/comments/1hdwaaz/2024_day_14_part_2_merry_christmas_i_guess/
bool has_long_line(vector<vector<bool>> &grid) {
    for (int i = 0; i < grid.size(); ++i) {
        int count = 0;
        for (int j = 0; j < grid[i].size(); ++j) {
            while (j < grid[i].size() && grid[i][j])
                ++count, ++j;
            if (count >= LONGLINE)
                return true;
            count = 0;
        }
    }
    return false;
}


// Modify input with:
// :%s/\a=//g
// :%s/,/ /g
int main() {
    vector<pair<int, int>> pos;
    vector<pair<int, int>> vel;
    int px, py, vx, vy;
    while (cin >> px >> py >> vx >> vy) {
        pos.push_back({px, py});
        vel.push_back({vx, vy});
    }

    for (int ans = 1; true; ++ans) {
        vector<vector<bool>> grid(HEIGHT, vector<bool>(WIDTH, false));
        for (int i = 0; i < pos.size(); ++i) { 
            pos[i].first = mod(pos[i].first + vel[i].first, WIDTH);
            pos[i].second = mod(pos[i].second + vel[i].second, HEIGHT);
            grid[pos[i].second][pos[i].first] = true;
        }
        if (has_long_line(grid)) {
            cout << ans << endl;
            return 0;
        }
    }
}

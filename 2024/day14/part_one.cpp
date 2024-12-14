#include <bits/stdc++.h>
using namespace std;

#define WIDTH 101
#define HEIGHT 103

inline int mod(int a, int n) {
    return ((a % n) + n) % n;
}


// Modify input with:
// :%s/\a=//g
// :%s/,/ /g
int main() {
    vector<pair<int, int>> pos;
    int px, py, vx, vy;
    while (cin >> px >> py >> vx >> vy) {
        px = mod(px + vx * 100, WIDTH);
        py = mod(py + vy * 100, HEIGHT);
        pos.push_back({px, py});
    }

    int top_left = 0, top_right = 0, bottom_left = 0, bottom_right = 0;
    for (auto [width, height] : pos) {
        top_left     += height < HEIGHT / 2 && width < WIDTH / 2;
        top_right    += height < HEIGHT / 2 && width > WIDTH / 2;
        bottom_left  += height > HEIGHT / 2 && width < WIDTH / 2;
        bottom_right += height > HEIGHT / 2 && width > WIDTH / 2;
    }

    cout << top_left * top_right * bottom_left * bottom_right << endl;
    return 0;
}

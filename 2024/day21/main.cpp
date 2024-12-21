#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


map<pair<int, int>, pair<vector<int>, vector<int>>> numerical_keypad;
map<pair<int, int>, pair<vector<int>, vector<int>>> directional_keypad;
void init_keypad(vector<string> &grid, map<pair<int, int>, pair<vector<int>, vector<int>>> &paths) {
    for (int si = 0; si < grid.size(); ++si) {
        for (int sj = 0; sj < grid[si].size(); ++sj) {
            for (int ei = 0; ei < grid.size(); ++ei) {
                for (int ej = 0; ej < grid[ei].size(); ++ej) {
                    char start = grid[si][sj], end = grid[ei][ej];
                    if (start == ' ' || end == ' ') continue;
                    vector<int> ans1, ans2;
                    int i = si, j = sj;
                    while (i != ei || j != ej) {
                        while (j < ej && grid[i][j + 1] != ' ') ans1.push_back('>'), ++j;
                        while (j > ej && grid[i][j - 1] != ' ') ans1.push_back('<'), --j;
                        while (i < ei && grid[i + 1][j] != ' ') ans1.push_back('v'), ++i;
                        while (i > ei && grid[i - 1][j] != ' ') ans1.push_back('^'), --i;
                    }
                    i = si, j = sj;
                    while (i != ei || j != ej) {
                        while (i != ei || j != ej) {
                            while (i < ei && grid[i + 1][j] != ' ') ans2.push_back('v'), ++i;
                            while (i > ei && grid[i - 1][j] != ' ') ans2.push_back('^'), --i;
                            while (j < ej && grid[i][j + 1] != ' ') ans2.push_back('>'), ++j;
                            while (j > ej && grid[i][j - 1] != ' ') ans2.push_back('<'), --j;
                        }
                    }
                    ans1.push_back('A');
                    ans2.push_back('A');
                    paths[{start, end}] = {ans1, ans2};
                }
            }
        }
    }
}


map<pair<vector<int>, int>, ll> memo;
ll solve(const vector<int> &moves, int robot) {
    if (robot == 0) return moves.size();
    if (memo[{moves, robot}]) return memo[{moves, robot}];

    ll ans = min(solve(directional_keypad[{'A', moves[0]}].first, robot - 1),
                 solve(directional_keypad[{'A', moves[0]}].second, robot - 1));
    for (int i = 0; i < moves.size() - 1; ++i) {
        ans += min(solve(directional_keypad[{moves[i], moves[i + 1]}].first, robot - 1),
                   solve(directional_keypad[{moves[i], moves[i + 1]}].second, robot - 1));
    }
    return memo[{moves, robot}] = ans;
}


int main() {
    int robots = 25;
    vector<string> num_grid = {"789", "456", "123", " 0A"};
    init_keypad(num_grid, numerical_keypad);
    vector<string> dir_grid = {" ^A", "<v>"};
    init_keypad(dir_grid, directional_keypad);

    ll ans = 0;
    string code;
    while (cin >> code) {
        ll num = 0, shortest = 0;
        for (int i = 0; i < code.length() - 1; ++i)
            num = num * 10 + code[i] - '0';
        code = "A" + code;
        for (int i = 0; i < code.size() - 1; ++i)
            shortest += min(solve(numerical_keypad[{code[i], code[i + 1]}].first, robots),
                            solve(numerical_keypad[{code[i], code[i + 1]}].second, robots));
        ans += shortest * num;
    }
    cout << ans << endl;
    return 0;
}

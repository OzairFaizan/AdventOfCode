#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<pair<ll, int>, ll> memo;

ll stones(ll stone, int to_blink) {
    if (to_blink == 0)
        return memo[{stone, to_blink}] = 1;
    if (memo[{stone, to_blink}])
        return memo[{stone, to_blink}];

    if (stone == 0)
        return memo[{stone, to_blink}] = stones(1LL, to_blink - 1);

    auto sstone = to_string(stone);
    auto slen = sstone.length();
    if (slen % 2 == 1)
        return memo[{stone, to_blink}] = stones(stone * 2024, to_blink - 1);

    ll left = stoll(sstone.substr(0, slen / 2));
    ll right = stoll(sstone.substr(slen / 2));
    return memo[{stone, to_blink}] = stones(left, to_blink - 1) + stones(right, to_blink - 1);
}

int main() {
    ll stone, ans = 0;
    int to_blink = 75;
    while (cin >> stone)
        ans += stones(stone, to_blink);
    cout << ans << endl;
    return 0;
}

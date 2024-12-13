#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Modify input using:
// :%s/Button \a: //g
// :%s/\a+//g
// :%s/Prize: //g
// :%s/\a=//g
// :%s/,/
// :%s/\n\n/\r
int main() {
    bool part_two = false;
    ll xa, ya, xb, yb, x, y, ans = 0;
    while (cin >> xa >> ya >> xb >> yb >> x >> y) {
        x += 10000000000000 * part_two;
        y += 10000000000000 * part_two;
        ll det = xa * yb - xb * ya;
        ll a = (x * yb - y * xb) / det;
        ll b = (y * xa - x * ya) / det;
        if ((x * yb - y * xb) % det == 0)
            ans += 3 * a + b;
    }
    cout << ans << endl;
    return 0;
}

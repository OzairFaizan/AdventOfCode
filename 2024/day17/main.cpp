#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A = 33024962, B = 0, C = 0;
vector<int> program = {2, 4, 1, 3, 7, 5, 1, 5, 0, 3, 4, 2, 5, 5, 3, 0};

vector<ll> part_one(ll a, ll b, ll c) {
    vector<ll> ans;
    int i = 0;
    while (i < program.size()) {
        int op = program[i], literal = program[i + 1], combo;
        switch (literal) {
            case 4: combo = a; break;
            case 5: combo = b; break;
            case 6: combo = c; break;
            default: combo = literal; break;
        }
        switch (op) {
            case 0: a = a >> combo; break;
            case 1: b = b ^ literal; break;
            case 2: b = combo & 7; break;
            case 3:
                if (a != 0)
                    i = literal - 2;
                break;
            case 4: b = b ^ c; break;
            case 5: ans.push_back(b & 7); break;
            case 6: b = a >> combo; break;
            case 7: c = a >> combo; break;
        }
        i += 2;
    }
    return ans;
}

ll part_two(ll a, ll b, ll c) {
    queue<ll> valid; valid.push(0);
    while (!valid.empty()) {
        ll va = valid.front(); valid.pop();

        for (int i = 0; i < 8; ++i) {
            ll pa = (va << 3) | i;
            ll ca = pa;
            vector<ll> curr = part_one(ca, b, c);
            auto cs = curr.size(), ps = program.size();
            bool ok_a = cs <= ps;
            for (int i = 0; ok_a && i < curr.size(); ++i)
                if (curr[cs - i - 1] != program[ps - i - 1])
                    ok_a = false;
            if (ok_a && cs == ps)
                return pa;
            if (ok_a)
                valid.push(pa);
        }
    }
    return -1;
}

int main() {
    auto part1 = part_one(A, B, C);
    cout << "Part one: " << part1[0];
    for (int i = 1; i < part1.size(); ++i)
        cout << ',' << part1[i];
    cout << endl << "Part two: " << part_two(A, B, C) << endl;
    return 0;
}

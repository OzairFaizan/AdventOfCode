#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<string, ll> memo;
ll designs(string target, vector<string> &available) {
    if (target.length() == 0) return 1;
    if (memo[target]) return memo[target];

    ll count = 0;
    for (auto av : available) {
        if (target.starts_with(av)) {
            count += designs(target.substr(av.length()), available);
        }
    }
    return memo[target] = count;
}


// add ',' after the last pattern
int main() {
    vector<string> available, targets;
    string s;
    while (cin >> s) {
        if (s.back() == ',')
            available.push_back(s.substr(0, s.length() - 1));
        else
            targets.push_back(s);
    }

    ll part_one = 0;
    ll part_two = 0;
    for (auto target : targets) {
        ll count = designs(target, available);
        part_one += count > 0;
        part_two += count;
    }

    cout << "Part one: " << part_one << endl;
    cout << "Part two: " << part_two << endl;
    return 0;
}

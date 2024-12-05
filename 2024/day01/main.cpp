#include <bits/stdc++.h>
using namespace std;

int part_one() {
    vector<int> first, second;
    int f, s;
    while (cin >> f >> s) {
        first.push_back(f);
        second.push_back(s);
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    int distance = 0;
    for (size_t i = 0; i < first.size(); ++i) {
        distance += abs(first[i] - second[i]);
    }

    return distance;
}

int part_two() {
    vector<int> first;
    unordered_map<int, int> second;
    int f, s;
    while (cin >> f >> s) {
        first.push_back(f);
        ++second[s];
    }

    size_t similarity = 0;
    for (int i : first) {
        similarity += i * second[i];
    }

    return similarity;
}

int main() {
    // cout << part_one() << endl;
    cout << part_two() << endl;
    return 0;
}

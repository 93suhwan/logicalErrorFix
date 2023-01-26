#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    unordered_map<char, int> map;
    for (auto it = s.begin(); it != s.end(); it++) {
      if (map.find(*it) == map.end()) {
        map[*it] = 1;
      } else {
        map[*it]++;
      }
    }
    int distinct = map.size();
    int total = s.size();
    float k = 0;
    if (distinct * 2 == total) {
      k = distinct;
    } else if (distinct * 2 < total) {
      if (distinct == 1) {
        k = 1;
      } else {
        int temp = total - distinct;
        k = temp - distinct;
      }
    } else {
      k = total / 2;
    }
    cout << k << "\n";
  }
}

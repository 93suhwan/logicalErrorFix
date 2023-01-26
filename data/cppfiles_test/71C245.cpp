#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1);
void solve() {
  string n;
  int k;
  cin >> n >> k;
  int num = 81;
  while (num--) {
    unordered_set<char> s;
    for (auto c : n) s.insert(c);
    if (s.size() <= k) {
      cout << n << "\n";
      break;
    }
    s.clear();
    int pos = 0;
    for (;; pos++) {
      s.insert(n[pos]);
      if (s.size() > k) {
        while (n[pos] == '9') {
          pos--;
        }
        n[pos]++;
        for (int i = pos + 1; i < n.size(); i++) {
          n[i] = '0';
        }
        break;
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}

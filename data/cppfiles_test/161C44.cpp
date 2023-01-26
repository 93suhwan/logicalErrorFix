#include <bits/stdc++.h>
using namespace std;
const int N = 2000, mod = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int> > q(n);
  vector<int> st(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> q[i].first >> q[i].second;
  }
  sort(q.begin(), q.end(),
       [](const pair<int, int> &a, const pair<int, int> &b) {
         return a.second - a.first < b.second - b.first;
       });
  for (int i = 0; i < n; i++) {
    int p = 1;
    for (int j = q[i].first; j <= q[i].second; j++) {
      if (st[j]) continue;
      st[j] = 1;
      p = j;
      break;
    }
    cout << q[i].first << ' ' << q[i].second << ' ' << p << '\n';
  }
  puts("");
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

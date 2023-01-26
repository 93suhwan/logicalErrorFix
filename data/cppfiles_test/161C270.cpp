#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, mod = 998244353;
pair<int, int> q[N];
void solve() {
  int n;
  cin >> n;
  vector<int> st(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> q[i].first >> q[i].second;
  }
  sort(q, q + n, [](pair<int, int> a, pair<int, int> b) {
    return a.second - a.first < b.second - b.first;
  });
  for (int i = 0; i < n; i++) {
    int p;
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

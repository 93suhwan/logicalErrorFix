#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  int x[n];
  for (auto &e : x) cin >> e;
  string s[n];
  for (auto &e : s) cin >> e;
  int ans = -1;
  vector<int> best(m, -1);
  for (int t = 0; t < (1 << n); t++) {
    int c[m];
    int cur = 0;
    for (int i = 0; i < n; i++) {
      int sign = (t & (1 << i)) ? 1 : -1;
      cur -= x[i] * sign;
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '1') c[j] += sign;
      }
    }
    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) { return c[i] < c[j]; });
    for (int i = 0; i < m; i++) {
      cur += c[order[i]] * (i + 1);
    }
    if (cur > ans) {
      ans = cur;
      best = order;
    }
  }
  int p[m];
  for (int i = 0; i < m; i++) {
    p[best[i]] = i + 1;
  }
  for (auto &e : p) cout << e << " ";
  cout << endl;
}
int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}

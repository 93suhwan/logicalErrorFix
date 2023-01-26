#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  int64_t best = -1e18;
  vector<int> q(m);
  for (int mask = 0; mask < (1 << n); mask++) {
    int64_t cur = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i))
        cur += x[i];
      else
        cur -= x[i];
    }
    vector<pair<int, int>> a;
    for (int j = 0; j < m; j++) {
      int coeff = 0;
      for (int i = 0; i < n; i++) {
        if (s[i][j] == '1') {
          if (mask & (1 << i))
            coeff--;
          else
            coeff++;
        }
      }
      a.push_back({coeff, j});
    }
    sort(a.begin(), a.end());
    for (int k = 0; k < m; k++) cur += a[k].first * (k + 1);
    if (cur > best) {
      best = cur;
      for (int k = 0; k < m; k++) {
        int j = a[k].second;
        q[j] = k + 1;
      }
    }
  }
  for (int i = 0; i < m; i++) cout << q[i] << (i + 1 == m ? '\n' : ' ');
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}

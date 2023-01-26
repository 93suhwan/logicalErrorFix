#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50, mod = 998244353, sqr = 500;
int n, m, x[N], y[N], ans[505][505], ans2[N], pref[N], st[N];
vector<int> v[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  for (int i = 1; i <= m; i++) {
    int op, idx;
    cin >> op >> idx;
    if (x[idx] + y[idx] >= sqr)
      v[idx].push_back(i);
    else {
      if (op == 1) {
        st[idx] = i;
        int len = x[idx] + y[idx], start = st[idx] % len;
        for (int j = 0; j < len; j++) {
          int diff = (j - start + len) % len;
          if (diff >= x[idx]) ans[len][j]++;
        }
      } else {
        int len = x[idx] + y[idx], start = st[idx] % len;
        for (int j = 0; j < len; j++) {
          int diff = (j - start + len) % len;
          if (diff >= x[idx]) ans[len][j]--;
        }
      }
    }
    for (int len = 2; len < sqr; len++) ans2[i] += ans[len][i % len];
  }
  for (int i = 1; i <= n; i++) {
    if (v[i].empty()) continue;
    if (v[i].size() % 2) v[i].push_back(m + 1);
    for (int j = 0; j < v[i].size(); j += 2) {
      int start = v[i][j] + x[i], period = x[i] + y[i];
      while (start < v[i][j + 1]) {
        int en = start + y[i];
        en = min(en, v[i][j + 1]);
        pref[start]++;
        pref[en]--;
        start += period;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    pref[i] += pref[i - 1];
    cout << pref[i] + ans2[i] << '\n';
  }
}

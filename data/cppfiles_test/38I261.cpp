#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e6 + 5, lg = 20;
long long int SGT[4 * N];
void update(long long int idx, long long int s, long long int e,
            long long int si, long long int val) {
  if (s == e) {
    SGT[si] += val;
    return;
  }
  long long int m = (s + e) / 2;
  if (idx <= m)
    update(idx, s, m, 2 * si + 1, val);
  else
    update(idx, m + 1, e, 2 * si + 2, val);
  SGT[si] = max(SGT[2 * si + 1], SGT[2 * si + 2]);
}
long long int q(long long int l, long long int r, long long int s,
                long long int e, long long int si) {
  if (l > r || l > e || r < s) return 0;
  if (s >= l && e <= r) return SGT[si];
  long long int m = (s + e) / 2;
  return max(q(l, r, s, m, 2 * si + 1), q(l, r, m + 1, e, 2 * si + 2));
}
void runcases(long long int T) {
  long long int n, m;
  cin >> n >> m;
  vector<vector<long long int> > v(n, vector<long long int>(m, 0));
  long long int a[n][m];
  long long int b[n][m];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == '.') v[i][j] = 1;
      a[i][j] = b[i][j] = v[i][j];
    }
  }
  long long int x[m];
  memset(x, 0, sizeof(x));
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (v[i][j] == 1) {
        long long int l = (i - 1 >= 0) ? a[i - 1][j] : 1;
        long long int r = (j - 1 >= 0) ? a[i][j - 1] : 1;
        a[i][j] = l || r;
        if (a[i][j] == 0) {
          x[j - 1] = 1;
        }
      }
    }
  }
  for (long long int i = 0; i < m; i++) {
    update(i, 0, m - 1, 0, x[i]);
  }
  long long int qs;
  cin >> qs;
  while (qs--) {
    long long int x, y;
    cin >> x >> y;
    --x, --y;
    long long int d = q(x, y, 0, m - 1, 0);
    if (!d) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T = 1;
  for (long long int t = 1; t <= T; t++) {
    runcases(t);
  }
  return 0;
}

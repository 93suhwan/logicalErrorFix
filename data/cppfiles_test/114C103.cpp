#include <bits/stdc++.h>
using namespace std;
inline void read(long long &x) {
  x = 0;
  long long f = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  x *= f;
}
template <typename _type>
void cmax(_type &a, _type b) {
  if (a < b) a = b;
}
template <typename _type>
void cmin(_type &a, _type b) {
  if (a > b) a = b;
}
const long long N = 200005;
long long i, j, k, m, n, s, t, sum;
long long a[11][N], b[N][11], c[11];
set<vector<long long> > st;
vector<long long> ans;
signed main() {
  read(n);
  for (i = 1; i <= n; i++) {
    read(c[i]);
    for (j = 1; j <= c[i]; j++) read(a[i][j]);
  }
  read(m);
  for (i = 1; i <= m; i++) {
    vector<long long> tmp;
    tmp.clear();
    for (j = 1; j <= n; j++) {
      read(b[i][j]);
      tmp.push_back(b[i][j]);
    }
    st.insert(tmp);
  }
  for (long long mask = 0; mask < 1 << n; mask++) {
    vector<long long> tmp;
    tmp.clear();
    long long opt = 0, flag = 0;
    for (k = 1; k <= n; k++) {
      if (c[k] - (mask & (1 << k - 1) ? 1 : 0) == 0) flag = 1;
      tmp.push_back(c[k] - (mask & (1 << k - 1) ? 1 : 0));
      opt += a[k][c[k] - (mask & (1 << k - 1) ? 1 : 0)];
    }
    if (st.count(tmp) || flag) continue;
    if (opt > sum) ans = tmp, sum = opt;
  }
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      if (b[i][j] == 1) continue;
      vector<long long> tmp;
      tmp.clear();
      long long opt = 0;
      for (k = 1; k <= n; k++) {
        tmp.push_back(b[i][k] - (k == j));
        opt += a[k][b[i][k] - (k == j)];
      }
      if (st.count(tmp)) continue;
      if (opt > sum) ans = tmp, sum = opt;
    }
  }
  for (long long v : ans) printf("%lld ", v);
  return 0;
}

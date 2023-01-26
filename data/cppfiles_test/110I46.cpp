#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, n1, n2, n3;
long long x[N], y[N];
int c[N], co[N];
long long t[N];
int d1[N], d2[N];
inline int qry(int s) {
  int c1 = 0, c2 = 0, res = 0, i, pos = 0;
  for (i = (1 << 16); i; i >>= 1) {
    if (pos + i > m) continue;
    if (c1 + d1[pos + i] <= s - c2 - d2[pos + i]) {
      pos += i;
      c1 += d1[pos];
      c2 += d2[pos];
    }
  }
  res = min(c1, s - c2);
  if (pos < m) {
    c1 = 0;
    c2 = 0;
    for (i = pos + 1; i; i -= (i & (-i))) {
      c1 += d1[i];
      c2 += d2[i];
    }
    res = max(res, min(c1, s - c2));
  }
  return res;
}
inline int solve() {
  int i, j;
  for (i = 1; i <= n; i++) t[i] = y[i];
  sort(t + 1, t + n + 1);
  m = unique(t + 1, t + n + 1) - (t + 1);
  vector<pair<long long, int> > v1, v2, v3;
  for (i = 1; i <= n; i++) {
    int z = lower_bound(t + 1, t + m + 1, y[i]) - t;
    if (c[i] == 1) v1.push_back({x[i], z});
    if (c[i] == 2) v2.push_back({x[i], z});
    if (c[i] == 3) v3.push_back({x[i], z});
  }
  n1 = v1.size();
  n2 = v2.size();
  n3 = v3.size();
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  sort(v3.begin(), v3.end());
  for (i = 1; i <= m; i++) d1[i] = d2[i] = 0;
  int p1 = 0, p2 = 0, res = 0;
  for (i = 0; i < n3; i++) {
    while (p1 < n1 && v1[p1].first < v3[i].first) {
      for (j = v1[p1].second; j <= m; j += (j & (-j))) d1[j]++;
      p1++;
    }
    while (p2 < n2 && v2[p2].first < v3[i].first) {
      for (j = v2[p2].second; j <= m; j += (j & (-j))) d2[j]++;
      p2++;
    }
    res = max(res, min(n3 - i, qry(p2)));
  }
  return res;
}
int main() {
  int i, j;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> x[i] >> y[i] >> co[i];
  int ans = 0;
  for (j = 1; j <= 4; j++) {
    int f[4] = {0, 1, 2, 3};
    do {
      for (i = 1; i <= n; i++) c[i] = f[co[i]];
      ans = max(ans, solve());
    } while (next_permutation(f + 1, f + 4));
    for (i = 1; i <= n; i++) {
      swap(x[i], y[i]);
      y[i] = -y[i];
    }
  }
  cout << ans * 3;
  return 0;
}

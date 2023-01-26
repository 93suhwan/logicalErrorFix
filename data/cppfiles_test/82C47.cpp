#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, q, k, a[300006], b[300006];
deque<int> que;
vector<int> v[300006], nx[300006], st[21][300006];
vector<long long> f[300006];
int main() {
  scanf("%d%d%d", &n, &q, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++i) {
    while (que.size() && a[i] <= a[que.back()]) que.pop_back();
    que.push_back(i);
    while (i - k > que.front()) que.pop_front();
    b[i] = a[que.front()];
    v[i % k].push_back(b[i]);
  }
  que.clear();
  for (int i = 0; i < k; ++i) {
    nx[i].resize(v[i].size());
    f[i].resize(v[i].size());
    for (int j = 0; j <= 20; ++j) st[j][i].resize(v[i].size());
  }
  for (int i = 0; i < k; ++i) {
    int len = v[i].size();
    for (int j = 0; j < len; ++j) {
      while (que.size() && v[i][j] < v[i][que.back()]) {
        nx[i][que.back()] = j;
        que.pop_back();
      }
      que.push_back(j);
    }
    while (que.size()) nx[i][que.back()] = len, que.pop_back();
    for (int j = len - 1; j >= 0; --j) {
      long long las = (nx[i][j] == len) ? 0 : f[i][nx[i][j]];
      f[i][j] = las + 1ll * v[i][j] * (nx[i][j] - j);
    }
  }
  for (int i = 0; i < k; ++i) {
    int len = st[0][i].size();
    for (int j = 0; j < len; ++j) st[0][i][j] = j;
  }
  for (int j = 1; j <= 20; ++j) {
    for (int i = 0; i < k; ++i) {
      int len = st[j][i].size();
      for (int p = 0; p < len; ++p) {
        if (st[j - 1][i][p] != -1) {
          long long t1 = v[i][st[j - 1][i][p]],
                    t2 = ((p + (1 << (j - 1))) < len)
                             ? v[i][st[j - 1][i][p + (1 << (j - 1))]]
                             : -1;
          if (t2 == -1)
            st[j][i][p] = st[j - 1][i][p];
          else if (t1 < t2)
            st[j][i][p] = st[j - 1][i][p];
          else
            st[j][i][p] = st[j - 1][i][p + (1 << (j - 1))];
        } else
          st[j][i][p] = -1;
      }
    }
  }
  for (int i = 1; i <= q; ++i) {
    int tl, tr;
    scanf("%d%d", &tl, &tr);
    if (tr - tl + 1 <= k) {
      printf("%d\n", a[tl]);
      continue;
    }
    int bel = tl % k, l = (tl + k + k - 1) / k - 1, len = (tr - tl - k) / k,
        r = l + len, mn = -1, oril = l;
    for (int j = 20; j >= 0 && l <= r; --j) {
      if (l + (1 << j) - 1 <= r) {
        if (mn == -1 ||
            (st[j][bel][l] != -1 && v[bel][st[j][bel][l]] < v[bel][mn])) {
          mn = st[j][bel][l];
        }
        l += (1 << j);
      }
    }
    printf("%lld\n", (long long)a[tl] + f[bel][oril] - f[bel][mn] +
                         (long long)(r - mn + 1) * v[bel][mn]);
  }
}

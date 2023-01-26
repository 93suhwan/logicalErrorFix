#include <bits/stdc++.h>
using namespace std;
int const N = 300300, M = 20;
struct RMQ {
  int s[N];
  int n, lg[N], d[M][N], pos[M][N];
  void init(int _n) {
    n = _n;
    lg[0] = -1;
    for (int i = 1; i <= (n); ++i) {
      lg[i] = lg[i - 1] + !(i & (i - 1));
      d[0][i] = s[i];
      pos[0][i] = i;
    }
    for (int i = 1; (1 << i) <= n; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
        d[i][j] = min(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
        if (d[i - 1][j] < d[i - 1][j + (1 << (i - 1))]) {
          d[i][j] = d[i - 1][j];
          pos[i][j] = pos[i - 1][j];
        } else {
          d[i][j] = d[i - 1][j + (1 << (i - 1))];
          pos[i][j] = pos[i - 1][j + (1 << (i - 1))];
        }
      }
    }
  }
  int get_mi(int a, int b) {
    int k = lg[b - a + 1];
    return min(d[k][a], d[k][b - (1 << k) + 1]);
  }
  int get_mi_pos(int a, int b) {
    int k = lg[b - a + 1];
    if (d[k][a] < d[k][b - (1 << k) + 1]) {
      return pos[k][a];
    } else {
      return pos[k][b - (1 << k) + 1];
    }
  }
} rmq;
int a[N], b[N], c[N], nxt[N];
long long f[N];
pair<int, int> st[N];
int top;
int ask[N][2];
long long ans[N];
vector<int> v[N];
int main() {
  int n, q, k;
  scanf("%d%d%d", &n, &q, &k);
  for (int i = 1; i <= (n); ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= (n); ++i) rmq.s[i] = a[i];
  rmq.init(n);
  for (int i = 1; i <= (n); ++i) b[i] = rmq.get_mi(max(1, i - k), i);
  for (int i = 0; i < (q); ++i) {
    scanf("%d%d", &ask[i][0], &ask[i][1]);
    v[ask[i][0] % k].push_back(i);
  }
  for (int i = 0; i < (k); ++i) {
    int vz = v[i].size();
    if (vz == 0) continue;
    int m = 0;
    for (int j = i == 0 ? k : i; j <= n; j += k) {
      c[++m] = b[j];
    }
    for (int j = 1; j <= (m); ++j) rmq.s[j] = c[j];
    rmq.init(m);
    top = 0;
    st[++top] = make_pair(m + 1, 0);
    for (int j = m; j >= 1; --j) {
      while (top > 0 && st[top].second > c[j]) {
        --top;
      }
      nxt[j] = st[top].first;
      if (st[top].second == c[j]) {
        st[top].first = j;
      } else {
        st[++top] = make_pair(j, c[j]);
      }
    }
    f[m + 1] = 0;
    for (int j = m; j >= 1; --j) {
      int x = nxt[j];
      f[j] = f[x] + 1LL * c[j] * (x - j);
    }
    for (int j = 0; j < (vz); ++j) {
      int x = v[i][j];
      int l = (ask[x][0] + k - 1) / k + 1, r = (ask[x][1] + k - 1) / k;
      ans[x] = a[ask[x][0]];
      if (l <= r) {
        int pos = rmq.get_mi_pos(l, r);
        long long ret = f[l] - f[pos] + 1LL * c[pos] * (r - pos + 1);
        ans[x] += ret;
      }
    }
  }
  for (int i = 0; i < (q); ++i) printf("%lld\n", ans[i]);
  return 0;
}

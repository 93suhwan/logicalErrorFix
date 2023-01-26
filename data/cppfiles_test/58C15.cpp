#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n, m, y[200011], p[200011], id;
int v[200011];
struct sgt {
  int sum[800011];
  void clear(int k, int l, int r) {
    sum[k] = r - l + 1;
    if (l == r) return;
    int mid = (l + r) >> 1;
    clear(k << 1, l, mid);
    clear(k << 1 | 1, mid + 1, r);
  }
  void modify(int k, int l, int r, int w, int num) {
    if (l == r) {
      sum[k] = num;
      return;
    }
    int mid = (l + r) >> 1;
    if (w <= mid)
      modify(k << 1, l, mid, w, num);
    else
      modify(k << 1 | 1, mid + 1, r, w, num);
    sum[k] = sum[k << 1] + sum[k << 1 | 1];
  }
  int find(int k, int l, int r, int rk) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (mid - l + 1 - sum[k << 1] >= rk)
      return find(k << 1, l, mid, rk);
    else
      return find(k << 1 | 1, mid + 1, r, rk - (mid - l + 1 - sum[k << 1]));
  }
} t;
long long inp[400011];
long long pw(long long s1, long long s2) {
  if (!s2) return 1;
  if (s2 % 2) return s1 * pw(s1, s2 - 1) % mod;
  long long ret = pw(s1, s2 / 2);
  return ret * ret % mod;
}
void solve() {
  id++;
  int c = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &y[i], &y[i]);
  for (int i = m; i >= 1; i--) {
    int l = t.find(1, 1, n, y[i]), r = t.find(1, 1, n, y[i] + 1);
    if (v[r] != id) c++;
    v[r] = id;
    t.modify(1, 1, n, l, 1);
    p[i] = l;
  }
  for (int i = 1; i <= m; i++) t.modify(1, 1, n, p[i], 0);
  cout << inp[2 * n - 1 - c] * pw(inp[n], mod - 2) % mod *
              pw(inp[n - 1 - c], mod - 2) % mod
       << endl;
}
int main() {
  inp[0] = 1;
  for (int i = 1; i <= 400000; i++) inp[i] = inp[i - 1] * i % mod;
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}

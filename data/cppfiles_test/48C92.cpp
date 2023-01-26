#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, q, a[maxn], b[maxn];
long long s[maxn];
struct RMQ {
  long long maxv[18][maxn], minv[18][maxn];
  int Log[maxn];
  RMQ() {
    Log[1] = 0;
    for (int i = 2; i < maxn; ++i) Log[i] = Log[i / 2] + 1;
  }
  void build(long long *x, int n) {
    for (int i = 1; i <= n; ++i) maxv[0][i] = minv[0][i] = x[i];
    for (int i = 1; i < 18; ++i)
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
        maxv[i][j] = max(maxv[i - 1][j + (1 << (i - 1))], maxv[i - 1][j]);
        minv[i][j] = min(minv[i - 1][j + (1 << (i - 1))], minv[i - 1][j]);
      }
  }
  long long getMax(int l, int r) {
    int d = r - l + 1, k = Log[d];
    return max(maxv[k][l], maxv[k][r - (1 << k) + 1]);
  }
  long long getMin(int l, int r) {
    int d = r - l + 1, k = Log[d];
    return min(minv[k][l], minv[k][r - (1 << k) + 1]);
  }
} r;
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  for (int i = 1; i <= n; ++i) {
    s[i] = b[i] - a[i];
    s[i] += s[i - 1];
  }
  r.build(s, n);
  for (int i = 1; i <= q; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    long long sum = r.getMin(x, y) - s[x - 1];
    if (sum < 0 || s[y] - s[x - 1] != 0) {
      puts("-1");
      continue;
    }
    long long res = r.getMax(x, y) - s[x - 1];
    printf("%lld\n", res);
  }
}

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * f;
}
long long Max(long long a = -1000000000000000000ll,
              long long b = -1000000000000000000ll,
              long long c = -1000000000000000000ll,
              long long d = -1000000000000000000ll,
              long long e = -1000000000000000000ll,
              long long f = -1000000000000000000ll,
              long long g = -1000000000000000000ll,
              long long h = -1000000000000000000ll) {
  return max(max(max(a, b), max(c, d)), max(max(e, f), max(g, h)));
}
long long Min(
    long long a = 1000000000000000000ll, long long b = 1000000000000000000ll,
    long long c = 1000000000000000000ll, long long d = 1000000000000000000ll,
    long long e = 1000000000000000000ll, long long f = 1000000000000000000ll,
    long long g = 1000000000000000000ll, long long h = 1000000000000000000ll) {
  return min(min(min(a, b), min(c, d)), min(min(e, f), min(g, h)));
}
int a[202020];
int get(int x) {
  int nw = 1;
  while (nw < x) {
    nw *= 2;
  }
  return nw - x;
}
int dis(int x) {
  if (x == 0) return 0;
  int ans = 0;
  return dis(get(x)) + 1;
}
int lca(int x, int y) {
  if (dis(x) < dis(y)) {
    swap(x, y);
  }
  while (dis(x) > dis(y)) {
    x = get(x);
  }
  if (x == y) return x;
  while (x != y) {
    x = get(x);
    y = get(y);
  }
  return x;
}
int dist(int x, int y) { return dis(x) + dis(y) - 2 * dis(lca(x, y)); }
signed main() {
  int T = 1;
  while (T--) {
    n = read();
    for (int i = 1, iend = n; i <= iend; ++i) a[i] = read();
    int px = 1;
    for (int i = 2, iend = n; i <= iend; ++i) {
      if (dist(1, a[i]) > dist(1, a[px])) {
        px = i;
      }
    }
    int py = px;
    for (int i = 1, iend = n; i <= iend; ++i) {
      if (dist(a[px], a[i]) > dist(a[px], a[py])) {
        py = i;
      }
    }
    cout << px << " " << py << " " << dist(a[px], a[py]);
  }
}

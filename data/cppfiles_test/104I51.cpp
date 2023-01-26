#include <bits/stdc++.h>
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(long long &x) { scanf("%lld", &x); }
void sc(long long &x, long long &y) { scanf("%lld%lld", &x, &y); }
void sc(long long &x, long long &y, long long &z) {
  scanf("%lld%lld%lld", &x, &y, &z);
}
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(long long x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(long long x, long long y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(long long x, long long y, long long z) {
  printf("%lld %lld %lld\n", x, y, z);
}
using namespace std;
void ast(long long x, long long l, long long r) { assert(x >= l && x <= r); }
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l, int r) { return uniform_int_distribution<int>(l, r)(gen); }
const int N = 2e5 + 5, mod = 1e6 + 5;
int n, m, a[N], b[N], c[N], d[N];
int main() {
  int t;
  sc(t);
  while (t--) {
    sc(n);
    sc(m);
    for (int i = 1; i <= n; i++) sc(a[i], b[i]), c[i] = d[i] = 0;
    long long sa = 0, sb = 0;
    for (int i = 1; i <= n; i++) {
      int t = min(a[i], m);
      a[i] -= t;
      c[i] += t;
      t = m - t;
      b[i] -= t;
      d[i] += t;
      sa += a[i];
      sb += b[i];
    }
    if (sb > sa) {
      for (int i = 1; i <= n; i++) {
        int t = (sb - sa) / 2;
        t = min(t, c[i]);
        t = min(t, b[i]);
        sa += t;
        sb -= t;
        c[i] -= t;
        d[i] += t;
        a[i] += t;
        b[i] -= t;
      }
    } else {
      for (int i = 1; i <= n; i++) {
        int t = (sa - sb) / 2;
        t = min(t, d[i]);
        t = min(t, a[i]);
        sa -= t;
        sb += t;
        c[i] += t;
        d[i] -= t;
        a[i] -= t;
        b[i] += t;
      }
    }
    out(abs(sa - sb));
    for (int i = 1; i <= n; i++) out(c[i], d[i]);
  }
}

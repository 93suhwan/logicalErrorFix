#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e3 + 3, inf = 2e18 + 7;
long long bin_pow(long long a, long long b) {
  long long x = 1;
  while (b) {
    if (b & 1) x *= a;
    a *= a;
    b >>= 1;
  }
}
long long readint() {
  long long x = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar(), f |= c == '-';
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return f ? -x : x;
}
string readstring() {
  string s = "";
  char c = getchar();
  while (!isalpha(c)) c = getchar();
  while (isalpha(c)) s += c, c = getchar();
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
void println(long long x) {
  print(x);
  putchar('\n');
}
void printsp(long long x) {
  print(x);
  putchar(' ');
}
void printyn(bool i) {
  if (i) {
    putchar('Y');
    putchar('E');
    putchar('S');
  } else {
    putchar('N');
    putchar('O');
  }
  putchar('\n');
};
struct dsu {
  long long p[maxn], r[maxn];
  long long n;
  dsu(long long n) {
    this->n = n;
    for (long long i = 0; i < n; ++i) p[i] = 1, r[i] = 0;
  }
  long long find(long long u) { return p[u] == u ? u : p[u] = find(p[u]); }
  bool unite(long long u, long long v) {
    u = find(u);
    v = find(v);
    if (r[u] < r[v]) swap(u, v);
    p[v] = u;
    r[u] += r[v];
  }
};
struct fw {
  long long t[maxn];
  long long n;
  fw(long long n) { this->n = n; }
  void upd(long long i, long long d) {
    for (; i < n; i |= i + 1) t[i] += d;
  }
  long long sum(long long i) {
    long long x = 0;
    for (; i >= 0; i &= i + 1, --i) x += t[i];
    return x;
  }
};
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a > b ? b : a; }
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long len(long long x) {
  if (x > 0) return len(x / 10) + 1;
}
long long len2(long long x) {
  if (x == 1)
    return 1;
  else
    return len2(x - 1) * 10;
}
long long a[maxn][maxn];
signed main() {
  long long n = readint(), m = readint(), q = readint(), ans = n * m;
  for (long long i = 0; i < n; ++i)
    for (long long j = 0; j < m; ++j) a[i][j] = 1;
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      if (i == 0) {
        for (long long k = 1;; ++k) {
          long long kx = i + k / 2, ky = j + (k + 1) / 2;
          if (kx == n || ky == m) break;
          ans += k;
        }
      }
      if (j == 0) {
        for (long long k = 1;; ++k) {
          long long kx = i + (k + 1) / 2, ky = j + k / 2;
          if (kx == n || ky == m) break;
          ans += k;
        }
      }
    }
  }
  while (q--) {
    long long x = readint() - 1, y = readint() - 1;
    for (long long c = 0; c < 2; ++c) {
      long long l = 1, r = 1;
      while (true) {
        long long kx = x + (l + c) / 2, ky = y + (l + !c) / 2;
        if (kx == n || ky == m || a[kx][ky] == 0) break;
        ++l;
      }
      while (true) {
        long long kx = x - (r + !c) / 2, ky = y - (r + c) / 2;
        if (kx < 0 || ky < 0 || a[kx][ky] == 0) break;
        ++r;
      }
      if (a[x][y] == 0)
        ans += l * r;
      else
        ans -= l * r;
    }
    ans += a[x][y];
    a[x][y] ^= 1;
    ans -= a[x][y];
    println(ans);
  }
}

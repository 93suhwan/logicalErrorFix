#include <bits/stdc++.h>
using namespace std;
const long long N = 5 * 1e5 + 100;
long long n, m, nxt[N], MAX[N];
char s[N], t[N];
inline void add(long long &a, long long b, long long mod) {
  a = ((a + b >= mod) ? a + b - mod : a + b);
}
inline void del(long long &a, long long b, long long mod) {
  a = ((a - b < 0) ? a - b + mod : a - b);
}
inline void mul(long long &a, long long b, long long mod) { a = a * b % mod; }
inline long long m_pow(long long a, long long b, long long mod) {
  long long ans = 1;
  while (b) {
    if (b & 1) mul(ans, a, mod);
    b >>= 1;
    mul(a, a, mod);
  }
  return ans;
}
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
struct Hash {
  long long a, b;
} z[N];
Hash h[N], x, th[N];
Hash operator+(Hash a, Hash b) {
  add(a.a, b.a, 998244353);
  add(a.b, b.b, 342914237);
  return a;
}
Hash operator-(Hash a, Hash b) {
  del(a.a, b.a, 998244353);
  del(a.b, b.b, 342914237);
  return a;
}
Hash operator*(Hash a, Hash b) {
  mul(a.a, b.a, 998244353);
  mul(a.b, b.b, 342914237);
  return a;
}
Hash operator*(Hash a, long long b) {
  mul(a.a, b, 998244353);
  mul(a.b, b, 342914237);
  return a;
}
bool operator==(Hash a, Hash b) { return a.a == b.a && a.b == b.b; }
Hash ask(long long l, long long r) { return h[r] - h[l - 1] * z[r - l + 1]; }
void check(long long a, long long b, long long c, long long d) {
  assert(b + 1 == c);
  if (a > b || c > d || d > n || a <= 0) return;
  if (ask(a, b) + ask(c, d) == x) {
    vector<long long> X, Y;
    if (b - a < d - c) swap(a, c), swap(b, d);
    for (long long i = b; i >= a; i--) X.push_back(s[i] - '0');
    for (long long i = d; i >= c; i--) Y.push_back(s[i] - '0');
    for (long long i = 0; i < (long long)Y.size(); i++) X[i] += Y[i];
    long long tmp = 0;
    for (long long i = 0; i < (long long)X.size(); i++) {
      X[i] += tmp;
      tmp = X[i] / 10;
      X[i] %= 10;
    }
    if (tmp) X.push_back(tmp);
    if ((long long)X.size() != m) return;
    bool bl = 1;
    for (long long i = 1; i <= m; i++)
      if (X[(long long)X.size() - i] != t[i] - '0') bl = 0;
    if (!bl) return;
    printf("%lld %lld\n%lld %lld\n", a, b, c, d);
    exit(0);
  }
}
long long find(long long i) {
  if (s[i] != t[1]) return 0;
  long long l = 1, r = m;
  while (l < r) {
    long long mid = l + ((r - l + 1) >> 1);
    if (ask(i, i + mid - 1) == th[mid])
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}
signed main() {
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  for (long long i = 1; i <= m; i++) {
    x = x * 10 + (Hash){t[i] - '0', t[i] - '0'};
    th[i] = x;
  }
  z[0] = (Hash){1, 1};
  for (long long i = 1; i <= n; i++) z[i] = z[i - 1] * (Hash){10, 10};
  for (long long i = 1; i <= n; i++)
    h[i] = h[i - 1] * 10 + (Hash){s[i] - '0', s[i] - '0'};
  for (long long i = 1; i <= n; i++) {
    check(i, i + m - 1, i + m, i + m + m - 1);
    check(i, i + m - 1, i + m, i + m + m - 2);
    check(i, i + m - 2, i + m - 1, i + m + m - 2);
    check(i, i + m - 2, i + m - 1, i + m + m - 3);
  }
  for (long long i = 1; i <= n; i++) {
    long long pos = find(i);
    if (pos == m) continue;
    check(i, i + m - 1, i + m, i + 2 * m - pos - 1);
    check(i, i + m - 1, i + m, i + 2 * m - pos - 2);
    check(i - (m - pos), i - 1, i, i + m - 1);
    check(i - (m - pos - 1), i - 1, i, i + m - 1);
  }
}

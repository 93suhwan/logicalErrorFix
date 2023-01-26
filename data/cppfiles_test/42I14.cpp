#include <bits/stdc++.h>
using namespace std;
inline long long readint() {
  long long x = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f ? -x : x;
}
const int maxn = 2e5 + 5;
int n, a[maxn * 2], b[maxn], t, q[maxn * 2];
bool v[maxn * 2];
const long long mod = 1e9 + 7;
inline int lowbit(int x) { return x & -x; }
long long c[maxn * 2];
void modify(int x, long long k) {
  while (x) {
    c[x] = (c[x] + k) % mod;
    x -= lowbit(x);
  }
}
long long query(int x) {
  long long s = 0;
  while (x <= n * 2) {
    s = (s + c[x]) % mod;
    x += lowbit(x);
  }
  return s;
}
long long f[maxn * 2];
int main() {
  n = readint();
  for (int i = 1; i <= n; i++) {
    int x = readint();
    b[i] = readint();
    a[b[i]] = x;
  }
  t = readint();
  for (int i = 1; i <= t; i++) v[b[readint()]] = 1;
  int l = 0;
  for (int i = n * 2; i > 0; i--)
    if (v[i]) {
      if (a[i] < l)
        v[i] = 0;
      else
        l = a[i];
    }
  for (int i = 1; i <= n * 2; i++)
    if (a[i]) {
      f[i] = (query(a[i]) + 1) % mod;
      modify(a[i], f[i]);
    }
  long long ans = 0, s = 0;
  for (int i = 1; i <= n * 2; i++)
    if (a[i]) {
      if (v[i]) ans = (ans + s + 1) % mod;
      s = (s + f[i]) % mod;
    }
  printf("%lld\n", ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  T f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ '0');
    s = getchar();
  }
  x *= f;
}
template <typename T>
void write(T x, char s = '\n') {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (!x) {
    putchar('0');
    putchar(s);
    return;
  }
  T tmp[25] = {}, t = 0;
  while (x) tmp[t++] = x % 10, x /= 10;
  while (t-- > 0) putchar(tmp[t] + '0');
  putchar(s);
}
const int MAXN = 2e5 + 5;
const int mod = 998244353;
const int N = 2e5;
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int tr[MAXN << 2];
long long fac[MAXN << 1], finv[MAXN << 1];
long long C(long long n, long long m) {
  return fac[n] * finv[n - m] % mod * finv[m] % mod;
}
void build(int l, int r, int now) {
  if (l == r) {
    tr[now] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, now << 1);
  build(mid + 1, r, now << 1 | 1);
  tr[now] = (tr[now << 1] + tr[now << 1 | 1]);
}
int find(int l, int r, int now, int v) {
  if (l == r) {
    tr[now] = 0;
    return l;
  }
  int mid = (l + r) >> 1;
  if (tr[now << 1] >= v) {
    int res = find(l, mid, now << 1, v);
    tr[now] = (tr[now << 1] + tr[now << 1 | 1]);
    return res;
  } else {
    int res = find(mid + 1, r, now << 1 | 1, v - tr[now << 1]);
    tr[now] = (tr[now << 1] + tr[now << 1 | 1]);
    return res;
  }
}
void update(int l, int r, int now) {
  if (l == r) {
    tr[now] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  if (tr[now << 1] != (mid - l + 1)) update(l, mid, now << 1);
  if (tr[now << 1 | 1] != (r - mid)) update(mid + 1, r, now << 1 | 1);
  tr[now] = r - l + 1;
}
vector<int> del;
int vis[MAXN << 1], X[MAXN], Y[MAXN];
int main() {
  build(1, N, 1);
  fac[0] = 1;
  for (int i = 1; i <= N * 2; ++i) fac[i] = fac[i - 1] * i % mod, vis[i] = 1;
  finv[N * 2] = qpow(fac[N * 2], mod - 2);
  for (int i = N * 2 - 1; i >= 0; --i) finv[i] = finv[i + 1] * (i + 1) % mod;
  int T;
  read(T);
  while (T-- > 0) {
    long long n, m;
    read(n), read(m);
    int ans = n - 1;
    for (int i = 1; i <= m; ++i) read(X[i]), read(Y[i]);
    for (int i = m; i >= 1; --i) {
      long long x = X[i], y = Y[i];
      int t = find(1, N, 1, y);
      vis[t] = 0;
      if (vis[t + 1]) ans--;
      del.push_back(t);
    }
    write(C(ans + n, n));
    for (int i = 0; i < (int)del.size(); ++i) {
      int x = del[i];
      vis[x] = 1;
    }
    del.clear();
    update(1, N, 1);
  }
  return 0;
}

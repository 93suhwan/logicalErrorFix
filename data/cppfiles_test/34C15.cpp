#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int head[1000005];
struct edge {
  int to, next;
};
edge e[1000005 << 1];
int cmt = 0;
int T;
int n, m;
int tree[1000005 << 2];
void Add(int x, int k) {
  while (x <= n) {
    tree[x] += k;
    x += x & -x;
  }
}
int Sum(int x) {
  int ans = 0;
  while (x != 0) {
    ans += tree[x];
    x -= x & -x;
  }
  return ans;
}
void add(int u, int v) {
  e[++cmt].to = v;
  e[cmt].next = head[u];
  head[u] = cmt;
}
template <typename Tp>
inline void read(Tp &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
int buf[42];
template <typename Tp>
inline void write(Tp x) {
  int p = 0;
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x == 0) {
    putchar('0');
    return;
  }
  while (x) {
    buf[++p] = x % 10;
    x /= 10;
  }
  for (int i = p; i; i--) putchar('0' + buf[i]);
}
long long quick(long long a, long long b) {
  long long ret = 1;
  long long now = a;
  while (b) {
    if (b & 1) {
      ret *= now;
      ret %= mod;
    }
    now *= now;
    now %= mod;
    b >>= 1;
  }
  return ret;
}
long long Inv(long long b) {
  if (b == 1) return 1;
  return (mod - mod / b) * Inv(mod % b) % mod;
}
long long fac[1000005], inv[1000005];
void getc() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < n; i++) fac[i] = fac[i - 1] * i % mod;
  inv[n - 1] = quick(fac[n - 1], mod - 2);
  for (int i = n - 2; i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
long long c(int a, int b) { return fac[n] * inv[m] % mod * inv[n - m] % mod; }
long long C(long long a, long long b, long long p) {
  if (b > a) return 0;
  long long res = 1;
  for (long long i = 1, j = a; i <= b; i++, j--) {
    res = res * j % p;
    res = res * quick(i, mod - 2) % p;
  }
  return res;
}
long long lucas(long long n, long long m, long long p) {
  return m ? lucas(n / p, m / p, p) * C(n % p, m % p, p) % p : 1;
}
map<int, int> mp;
int r[1 << 13], ans[1 << 13], cnt = 0;
;
int Ans[1000005];
vector<int> g[1000005];
int main() {
  T = 1;
  ans[0] = 1;
  while (T--) {
    read(n);
    for (int i = 0; i < 1 << 13; i++) {
      g[i].push_back(0);
      r[i] = 1 << 13;
    }
    for (int i = 1; i <= n; i++) {
      int x;
      read(x);
      for (auto v : g[x]) {
        int xv = x ^ v;
        ans[xv] = 1;
        while (r[xv] > x) {
          r[xv]--;
          if (r[xv] != x) {
            g[r[xv]].push_back(xv);
          }
        }
      }
      g[x].clear();
    }
    for (int i = 0; i < 1 << 13; i++) {
      if (ans[i]) Ans[++cnt] = i;
    }
    write(cnt);
    putchar('\n');
    for (int i = 1; i <= cnt; i++) printf("%d ", Ans[i]);
    cout << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 9;
const long long MOD = 1e9 + 7;
const int mod = 998244353;
inline long long qpow(long long b, long long e, long long m) {
  long long a = 1;
  for (; e; e >>= 1, b = b * b % m)
    if (e & 1) a = a * b % m;
  return a;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, x, y);
  long long z = x;
  x = y, y = z - y * (a / b);
  return d;
}
struct node {
  int a, b, dx, dy;
} l;
int n, m, a, b, c, d, p;
bool vis[maxn << 1][2][2];
int change(int x) {
  if (x == 1) return 1;
  return 0;
}
void solve(node &l) {
  l.a += l.dx;
  l.b += l.dy;
  if (l.dx == 1) {
    if (l.a == n) {
      l.dx = -1;
    }
  } else {
    if (l.a == 1) {
      l.dx = 1;
    }
  }
  if (l.dy == 1 && l.b == m) {
    l.dy = -1;
  }
  if (l.dy == -1 && l.b == 1) {
    l.dy = 1;
  }
}
int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    memset(vis, 0, sizeof(vis));
    scanf("%d%d%d%d%d%d%d", &n, &m, &a, &b, &c, &d, &p);
    vector<node> ve;
    long long pp = (long long)(100 - p) * qpow(100, MOD - 2, MOD) % MOD;
    l = {a, b, 1, 1};
    if (l.a == n) l.dx = -1;
    if (l.b == m) l.dy = -1;
    while (!vis[l.a * m + l.b][change(l.dx)][change(l.dy)]) {
      vis[l.a * m + l.b][change(l.dx)][change(l.dy)] = 1;
      solve(l);
      ve.push_back(l);
    }
    reverse(ve.begin(), ve.end());
    pair<long long, long long> par = {0, 1};
    for (int i = 0; i < ve.size(); i++) {
      par.first++;
      par.first %= MOD;
      if (ve[i].a == c || ve[i].b == d) {
        par.first = par.first * pp % MOD;
        par.second = par.second * pp % MOD;
      }
    }
    long long ans = par.first * qpow(1 - par.second + MOD, MOD - 2, MOD) % MOD;
    if (a != c && b != d) ans++;
    printf("%lld\n", ans % MOD);
  }
}

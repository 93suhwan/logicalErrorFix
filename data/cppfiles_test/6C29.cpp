#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 200010;
long long t, n, cnt, x, m, a[maxn], b[4 * maxn], tag[4 * maxn], ans, pos,
    c[maxn], l, r, mid, y, z, mx, k, mod = 1000000007, cnt1, cnt2, cnt3, cnt4,
                                     cnt5, cnt6, mn, vis[maxn], sum, pos1, pos2,
                                     dis[maxn];
long long dif[maxn];
long long tw[60], av, h;
double probability = 0;
set<long long> se;
vector<long long> v[maxn], gr[maxn], v1, v2, divv[maxn];
string s, s1, s2, s3, s4;
char cc[405][405], abc[205];
pair<long long, long long> p[maxn], pp;
map<long long, long long> mp;
char ch;
long long fpow(long long x, long long y) {
  if (y == 0) {
    return 1 % mod;
  }
  long long a = x % mod;
  long long a2 = 1 % mod;
  while (y > 1) {
    if (y % 2) {
      a2 *= a;
      a2 %= mod;
    }
    a *= a;
    a %= mod;
    y /= 2;
  }
  return (a * a2) % mod;
}
void build(long long l, long long r, long long v) {
  if (l == r) {
    b[v] = 0;
    return;
  }
  long long mid = (l + r) >> 1;
  build(l, mid, v << 1);
  build(mid + 1, r, v << 1 | 1);
  b[v] = 0;
}
long long qu(long long l, long long r, long long v, long long l2,
             long long r2) {
  if (l == l2 && r == r2) {
    return b[v];
  }
  tag[v << 1] += tag[v];
  b[v << 1] *= tw[tag[v]];
  b[v << 1] %= mod;
  tag[v << 1 | 1] += tag[v];
  b[v << 1 | 1] *= tw[tag[v]];
  b[v << 1 | 1] %= mod;
  tag[v] = 0;
  long long mid = (l + r) >> 1;
  if (mid >= r2) {
    return qu(l, mid, v << 1, l2, r2);
  } else if (mid + 1 <= l2) {
    return qu(mid + 1, r, v << 1 | 1, l2, r2);
  } else {
    return (qu(l, mid, v << 1, l2, mid) +
            qu(mid + 1, r, v << 1 | 1, mid + 1, r2)) %
           mod;
  }
}
void modify1(long long l, long long r, long long v, long long l2, long long r2,
             long long m) {
  if (l == l2 && r == r2) {
    b[v] = b[v] << 1;
    b[v] %= mod;
    tag[v]++;
    return;
  }
}
void modify2(long long l, long long r, long long v, long long l2,
             long long r2) {
  if (l == l2 && r == r2) {
    b[v]++;
    b[v] %= mod;
    return;
  }
  tag[v << 1] += tag[v];
  b[v << 1] *= tw[tag[v]];
  b[v << 1] %= mod;
  tag[v << 1 | 1] += tag[v];
  b[v << 1 | 1] *= tw[tag[v]];
  b[v << 1 | 1] %= mod;
  tag[v] = 0;
  long long mid = (l + r) >> 1;
  if (mid >= r2) {
    modify2(l, mid, v << 1, l2, r2);
  } else if (mid + 1 <= l2) {
    modify2(mid + 1, r, v << 1 | 1, l2, r2);
  } else {
    modify2(l, mid, v << 1, l2, mid);
    modify2(mid + 1, r, v << 1 | 1, mid + 1, r2);
  }
  b[v] = (b[v << 1] + b[v << 1 | 1]) % mod;
}
bool isp(long long x) {
  if (x == 1) {
    return 0;
  }
  for (long long i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  for (long long i = 1; i <= 100000; i++) {
    for (long long j = 1; j <= sqrt(i); j++) {
      if (i % j == 0) {
        divv[i].emplace_back(j);
        if (j != i / j) {
          divv[i].emplace_back(i / j);
        }
      }
    }
  }
  dif[1] = 1;
  for (long long i = 2; i <= 100000; i++) {
    dif[i] = i;
    for (long long j = 0; j < divv[i].size(); j++) {
      if (divv[i][j] != i) {
        dif[i] -= dif[divv[i][j]];
      }
    }
    dif[i] %= mod;
  }
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    v[a[i]].emplace_back(i);
  }
  ans = 0;
  for (long long i = 1; i <= 100000; i++) {
    cnt = 0;
    for (long long j = 1; i * j <= 100000; j++) {
      for (long long k = 0; k < v[i * j].size(); k++) {
        y = v[i * j][k];
        for (long long t = 0; t < divv[y].size(); t++) {
          if (!vis[divv[y][t]]) {
            b[cnt] = divv[y][t];
            cnt++;
            vis[divv[y][t]] = 1;
          }
          c[divv[y][t]]++;
        }
      }
    }
    x = 0;
    for (long long j = 0; j < cnt; j++) {
      x += (c[b[j]] * (c[b[j]] - 1) / 2 * dif[b[j]]);
      x %= mod;
    }
    for (long long j = 0; j < cnt; j++) {
      vis[b[j]] = 0;
      c[b[j]] = 0;
    }
    ans += (x)*dif[i];
    ans %= mod;
  }
  ans *= 2;
  for (long long i = 1; i <= n; i++) {
    ans += a[i] * i;
  }
  cout << (ans + mod) % mod;
}

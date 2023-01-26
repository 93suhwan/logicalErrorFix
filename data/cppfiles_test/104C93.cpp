#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 300010;
long long t, n, cnt, x, m, ans, pos, l, r, mid, a[maxn], b[maxn], c[maxn],
    c2[maxn], pre[maxn], nn[maxn], nn2[maxn], y, z, mx, k, cnt1, cnt2, cnt3,
    cnt4, cnt5, cnt6, mn, sum, pos1, pos2, vis[maxn], out[maxn];
long long dp[205][205];
long long mod = 998244353, mod2 = 1000000007;
long long fac[205], facn[205];
long long ccc[205][205], ex[205][205];
long long te[20];
long long tw[49];
set<long long> se;
vector<long long> v[maxn];
string s, s1, s2, s3, s4;
char cc[1005][1005], abc[205];
map<pair<long long, long long>, long long> mp, mp2;
pair<long long, long long> pp;
pair<pair<long long, long long>, long long> p[maxn], p2[maxn];
char ch;
map<char, long long> mm;
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
  b[v] = b[v << 1] + b[v << 1 | 1];
}
long long qu(long long l, long long r, long long v, long long l2,
             long long r2) {
  if (l == l2 && r == r2) {
    return b[v];
  }
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
void modify(long long l, long long r, long long v, long long l2, long long r2,
            long long m) {
  if (l == l2 && r == r2) {
    b[v] = m;
    return;
  }
  long long mid = (l + r) >> 1;
  if (mid >= r2) {
    modify(l, mid, v << 1, l2, r2, m);
  } else if (mid + 1 <= l2) {
    modify(mid + 1, r, v << 1 | 1, l2, r2, m);
  } else {
    modify(l, mid, v << 1, l2, mid, m);
    modify(mid + 1, r, v << 1 | 1, mid + 1, r2, m);
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
  cin >> t;
  while (t--) {
    cin >> n >> m;
    x = m * n;
    pos1 = 0;
    pos2 = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      pos1 += a[i];
      pos2 += b[i];
    }
    if (pos1 <= pos2) {
      if (pos1 + x <= pos2) {
        cnt = 0;
      } else {
        cnt = (x - pos2 + pos1) / 2;
      }
    } else {
      if (pos2 + x <= pos1) {
        cnt = x;
      } else {
        cnt = (x - pos2 + pos1) / 2;
      }
    }
    cnt2 = 0;
    for (long long i = 0; i < n; i++) {
      c[i] = max(0LL, m - b[i]);
      cnt2 += c[i];
    }
    if (cnt2 < cnt) {
      for (long long i = 0; i < n; i++) {
        k = min(a[i], m) - c[i];
        if (k >= cnt - cnt2) {
          c[i] += (cnt - cnt2);
          cnt2 = cnt;
          break;
        } else {
          cnt2 += (min(a[i], m) - c[i]);
          c[i] = min(a[i], m);
        }
      }
    }
    cout << abs((pos1 - cnt2) - (pos2 - m * n + cnt2)) << '\n';
    for (long long i = 0; i < n; i++) {
      cout << c[i] << " " << m - c[i] << '\n';
    }
  }
}

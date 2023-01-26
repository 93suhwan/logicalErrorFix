#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a > b)
    return b;
  else
    return a;
}
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
inline long long lcm(long long a, long long b) {
  return a / gcd(a, b) * 1LL * b;
}
inline long long normalize(long long x, long long mod) {
  x %= mod;
  if (x < 0) x += mod;
  return x;
}
long long dx[4] = {0, 1, 0, -1};
long long dy[4] = {1, 0, -1, 0};
string abc = "abcdefghijklmnopqrstuvwxyz";
const long long mod = 1000 * 1000 * 1000 + 7;
const long long inf = 1e18 + 5;
inline long long add(long long a, long long b, long long p = mod) {
  long long c = a + b;
  if (c >= p) c -= p;
  return c;
}
inline long long sub(long long a, long long b, long long p = mod) {
  long long c = a - b;
  if (c < 0) c += p;
  return c;
}
inline long long mul(long long a, long long b, long long p = mod) {
  return (a * 1LL * b) % p;
}
long long floor1(long long n, long long k) {
  if (n % k == 0 || n >= 0) return n / k;
  return (n / k) - 1;
}
long long ceil1(long long n, long long k) { return floor1(n + k - 1, k); }
long long powm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
const long long N = 2e5 + 5;
long long n;
long long a[N];
long long f[N], g[N];
void solve() {
  cin >> n;
  for (long long i = (1); i < (n + 1); ++i) cin >> a[i];
  for (long long i = (0); i < (n + 5); ++i) f[i] = g[i] = 0;
  for (long long i = (1); i < (n + 1); ++i) {
    ++f[a[i]];
  }
  g[0] = f[0];
  for (long long i = (1); i < (n + 1); ++i) {
    g[i] += g[i - 1] + (i + 1) * f[i];
  }
  for (long long i = (1); i < (n + 1); ++i) {
    f[i] += f[i - 1];
  }
  priority_queue<long long> q;
  vector<long long> ad(n + 5, 0);
  for (long long i = (0); i < (n + 1); ++i) {
    if (i == 0) {
      if (f[i] == 0) continue;
      for (long long j = (0); j < (f[i] - 1); ++j) {
        q.push(i);
      }
    } else if (i != 0 and f[i] - f[i - 1]) {
      if (f[i] - f[i - 1]) {
        for (long long j = (0); j < (f[i] - f[i - 1] - 1); ++j) {
          q.push(i);
        }
      }
      ad[i] += ad[i - 1];
    } else {
      if (((long long)q.size()) == 0) {
        ad[i] += ad[i - 1];
        ad[i] = -1;
        continue;
      }
      ad[i] = i - q.top();
      q.pop();
      ad[i] += ad[i - 1];
    }
  }
  long long flag = 1;
  long long ans = 0;
  for (long long i = (0); i < (n + 1); ++i) {
    if (flag == -1) {
      cout << -1 << " ";
      continue;
    }
    long long less = 0, cur = 0, lar = 0;
    if (i == 0) {
      cur = f[i];
      lar = n - cur;
      cout << cur << " ";
    } else {
      cur = f[i] - f[i - 1];
      lar = f[n] - f[i];
      less = f[i - 1];
      if (less < i) {
        flag = -1;
        cout << -1 << " ";
        continue;
      }
      if (i == n) {
        cout << ad[i - 1] << " ";
        continue;
      }
      ans = ad[i - 1] + cur;
      cout << ans << " ";
    }
  }
  cout << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  long long t = 1;
  cin >> t;
  for (long long i = (1); i < (t + 1); ++i) {
    solve();
  }
  return 0;
}

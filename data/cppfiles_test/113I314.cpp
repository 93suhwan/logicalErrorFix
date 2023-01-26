#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long MAX = 8000000000000000064LL;
const long long MIN = -8000000000000000064LL;
long long exp(long long x, long long y, long long p) {
  x %= p;
  long long res = 1;
  while (y) {
    if (y % 2) res = (res * x % p) % p;
    x = (x * x) % p;
    y /= 2;
  }
  return res;
}
long long expo(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y % 2) res = (res * x % ((long long)1e9 + 7)) % ((long long)1e9 + 7);
    x = (x * x) % ((long long)1e9 + 7);
    y /= 2;
  }
  return res;
}
long long add(long long a, long long b) {
  return (a % ((long long)1e9 + 7) + b % ((long long)1e9 + 7) +
          ((long long)1e9 + 7)) %
         ((long long)1e9 + 7);
}
long long sub(long long a, long long b) {
  return (a % ((long long)1e9 + 7) - b % ((long long)1e9 + 7) +
          ((long long)1e9 + 7)) %
         ((long long)1e9 + 7);
}
long long mul(long long a, long long b) {
  return ((a % ((long long)1e9 + 7)) * (b % ((long long)1e9 + 7)) +
          ((long long)1e9 + 7)) %
         ((long long)1e9 + 7);
}
long long inv(long long x) { return expo(x, ((long long)1e9 + 7) - 2); }
long long xyp(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y % 2 == 1) res = (res * x) % ((long long)1e9 + 7);
    x = (x * x) % ((long long)1e9 + 7);
    y /= 2;
  }
  return res % ((long long)1e9 + 7);
}
inline long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
inline long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& i : v) in >> i;
  return in;
}
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }
void solve() {
  long long n, k;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) cin >> a[i];
  ;
  sort(a.begin(), a.end());
  long long m, total = 0;
  for (long long i = 0; i < n; i++) {
    total += a[i];
  }
  cin >> m;
  long long x, y, p;
  while (m--) {
    cin >> x >> y;
    long long coin = 0;
    long long in = 0;
    auto it = upper_bound(a.begin(), a.end(), x);
    if (it != a.begin()) {
      it = prev(it);
      p = a[it - a.begin()];
      in = it - a.begin();
    } else {
      p = a[0];
      in = 0;
    }
    if (p < x) {
      coin += x - p;
    }
    long long pro = total - (p);
    if (pro < y) {
      long long r = y - pro;
      pro += r;
      coin += r;
    }
    cout << coin << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  for (long long i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long mx = 1e9 + 7;
long long power(long long x, long long n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  long long ret = power(x, n / 2);
  if (n % 2 == 0)
    return (ret * ret) % mx;
  else
    return ((ret * ret) % mx * x) % mx;
}
vector<long long> fac(2e5 + 5, 1);
long long inv(long long a) { return (power(a, mod - 2) % mod + mod) % mod; }
long long binom(long long x, long long y) {
  if (x < 0 || y < 0) return 0;
  return (((fac[x] * inv(fac[y])) % mod * inv(fac[x - y])) % mod + mod) % mod;
}
bool isPrime(long long n) {
  static long long i = 2;
  if (n == 0 || n == 1) {
    return false;
  }
  if (n == i) return true;
  if (n % i == 0) {
    return false;
  }
  i++;
  return isPrime(n);
}
string ffs(long long i) {
  if (i == 0)
    return "";
  else
    return ffs((i - 1) / 26) + char((i - 1) % 26 + 'a');
}
const long long ftr = 4e5 + 5;
const long long mod22 = 1e9 + 7;
bool checkcycle[ftr];
vector<long long> adj[ftr];
void rotatecycle(long long y) {
  checkcycle[y] = true;
  for (auto x : adj[y]) {
    if (!checkcycle[x]) rotatecycle(x);
  }
}
bool isPal(string &str) {
  long long l = 0;
  long long h = (long long)str.size() - 1;
  while (l < h) {
    if (str[l++] != str[h--]) {
      return false;
    }
  }
  return true;
}
long long xxxor(long long n) {
  if (n % 4 == 0) {
    return n;
  }
  if (n % 4 == 1) {
    return 1;
  }
  if (n % 4 == 2) {
    return n + 1;
  }
  return 0;
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
bool sortbysecgt(const pair<long long, long long> &a,
                 const pair<long long, long long> &b) {
  return (a.second > b.second);
}
const long long mmt = 1e14;
long long factorial(long long n) {
  long long res = 1;
  for (long long i = 1; i <= n; i++) {
    res = (res * i) % mmt;
  }
  return res;
}
void solve() {
  long long x, y;
  cin >> x >> y;
  long long out = 0;
  if (x > y) {
    cout << (x + y) << '\n';
  } else {
    out = (x + y) / 2;
    out %= x;
    y -= out;
    cout << y << "\n";
  }
}
int32_t main() {
  long long t;
  cin >> t;
  long long ind = 0;
  long long idx = 0;
  priority_queue<pair<long long, long long>> pq;
  vector<bool> vis(500005, false);
  long long mni = 1e9 + 7;
  while (t--) {
    solve();
  }
  return 0;
}

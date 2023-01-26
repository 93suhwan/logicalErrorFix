#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1.0);
long long mod = 1e9 + 7;
long long GCD(long long a, long long b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}
long long prod(long long &a, long long &b) {
  long long res = 0;
  a %= mod;
  while (b) {
    if (b & 1ll) res = (res + a) % mod;
    a = (2ll * a) % mod;
    b >>= 1ll;
  }
  return res;
}
long long power(long long a, long long b) {
  long long res = 1ll;
  while (b > 0) {
    if (b % 2ll) res = (res * a) % mod;
    a = (a * a) % mod;
    b /= 2ll;
  }
  return res;
}
long long binaryExponentiation(long long a, long long b) {
  long long result = 1ll;
  while (b > 0) {
    if (b % 2 == 1) result = (result * a) % mod;
    a = (a * a) % mod;
    b /= 2ll;
  }
  return result;
}
long long ModularInverse(long long a) {
  return binaryExponentiation(a, mod - 2);
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) {
    res = (res * i) % mod;
  }
  return res % mod;
}
long long nCr(long long n, long long r) {
  return (fact(n) * ModularInverse((fact(r) * fact(n - r)) % mod)) % mod;
}
long long maxn = 1e6;
bool cmp(vector<long long> &a, vector<long long> &b) {
  if (a[0] != b[0]) return a[0] < b[0];
  return a[1] > b[1];
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long ans = 0;
  vector<vector<long long>> a;
  vector<long long> b;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long x;
      cin >> x;
      a.push_back({x, 10});
      b.push_back(x);
    }
  }
  sort((b).begin(), (b).end());
  long long x = 1;
  map<long long, long long> com;
  for (long long i = 0; i < b.size(); i++) {
    if (i == 0 || b[i] != b[i - 1]) {
      com[b[i]] = x++;
    }
  }
  long long p = 0, q = 0;
  vector<vector<long long>> up(n + 1, vector<long long>(m + 1, 0));
  vector<set<long long>> xx(x + 1);
  for (long long i = 0; i < b.size();) {
    long long c = 0;
    for (long long j = i; j < b.size() and b[i] == b[j]; j++, c++) {
    }
    x = com[b[i]];
    for (long long j = 0; j < c; j++) {
      if (q == m) {
        p++, q = 0;
      }
      up[p][q] = x;
      xx[x].insert(p);
      q++;
    }
    i += c;
  }
  for (long long i = 0; i < a.size(); i++) {
    x = com[a[i][0]];
    long long p = *(xx[x].begin());
    long long q;
    for (q = 0; q < m; q++) {
      if (up[p][q] == -1) ans++;
      if (q < m - 1 and up[p][q] == x and up[p][q + 1] != x) {
        break;
      }
    }
    q = min(q, m - 1);
    up[p][q] = -1;
    if (q == 0 || up[p][q - 1] != x) {
      xx[x].erase(xx[x].begin());
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

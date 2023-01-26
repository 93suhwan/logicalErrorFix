#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long modpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
long long bpow(long long a, long long b) {
  if (b < 0) {
    return 0;
  }
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long modinv(long long a, long long m = MOD) { return modpow(a, m - 2, m); }
const int N = 5e5 + 5;
vector<long long> adj[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n, d;
    cin >> n >> d;
    vector<long long> a(n + 1);
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if (n == 1) {
      if (a[1] == 0) {
        cout << 0 << '\n';
      } else {
        cout << -1 << '\n';
      }
      continue;
    }
    vector<long long> par(n + 1);
    for (long long i = 1; i <= n; i++) {
      par[i] = (i + d);
      if (i + d > n) {
        par[i] = i + d - n;
      }
    }
    vector<long long> vis(n + 1, 0);
    vector<vector<long long> > v;
    for (long long i = 1; i <= n; i++) {
      if (!vis[i]) {
        vector<long long> c;
        long long k = i;
        while (par[k] != i) {
          vis[k] = 1;
          c.push_back(k);
          k = par[k];
        }
        vis[k] = 1;
        c.push_back(k);
        v.push_back(c);
      }
    }
    bool check = true;
    long long ans = 0;
    for (long long i = 0; i < (int)v.size(); i++) {
      vector<long long> c = v[i];
      long long cnt = 0;
      for (long long j = 0; j < (int)c.size(); j++) {
        if (a[c[j]] == 1) {
          cnt++;
        }
      }
      if (cnt == (int)c.size()) {
        check = false;
        break;
      }
      vector<long long> h = c;
      for (long long j = 0; j < (int)c.size(); j++) {
        h.push_back(c[j]);
      }
      long long mx = 0;
      cnt = 0;
      for (long long j = 0; j < (int)h.size(); j++) {
        if (a[h[j]] == 0) {
          mx = max(mx, cnt);
          cnt = 0;
        } else {
          cnt++;
        }
      }
      mx = max(mx, cnt);
      ans = max(ans, mx);
    }
    if (check) {
      cout << ans << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
}

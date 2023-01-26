#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target_tbl( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx", "sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T>
void show(const vector<T> &a) {
  for (T x : a) cout << x << " ";
  cout << '\n';
}
template <class T>
void showline(const vector<T> &a) {
  for (T x : a) cout << x << '\n';
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());
long long xx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
long long yy[8] = {0, 0, 1, -1, -1, -1, 1, 1};
string dir = "RDLU";
string travel = "ENWS";
const long long N = 3e5 + 50, oo = 1e18 + 500;
const long long mod = 1e9 + 9;
const long long M2 = 1000000093, x2 = 27162;
const long long M1 = 1000000087, x1 = 241;
const long double eps = 1e-8, PI = 2 * acos(0.0);
struct Hash {
  long long mod;
  long long x = 10;
  vector<long long> h;
  long long ht;
  vector<long long> deg;
  bool is_prime(long long n) {
    if (n <= 1) return false;
    for (long long j = 2; j * j <= n; j++) {
      if (n % j == 0) return false;
    }
    return true;
  }
  Hash() {
    uniform_int_distribution<long long> dis(1000000000, 2000000000);
    mod = dis(rng_64);
    while (!is_prime(mod)) mod++;
  }
  void build(string s, string t) {
    long long n = ((long long)(s.size()));
    h.resize(n + 10);
    deg.resize(n + 10);
    deg[0] = 1;
    for (long long i = 1; i <= n; i++) {
      h[i] = ((s[i - 1] - '0') + (i ? h[i - 1] * x : 0)) % mod;
      deg[i] = deg[i - 1] * x % mod;
    }
    ht = 0;
    for (long long i = 0; i < ((long long)(t.size())); i++)
      ht = ((t[i] - '0') + ht * x) % mod;
  }
  long long get(long long l, long long r) {
    return (h[r + 1] - h[l] * deg[r - l + 1] % mod + mod) % mod;
  }
};
vector<long long> z_function(string s) {
  long long n = (long long)s.length();
  vector<long long> z(n);
  for (long long i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
bool equal(vector<Hash> &vh, long long l1, long long r1, long long l2,
           long long r2) {
  if (l1 > r1 || l2 > r2) return false;
  bool fl = 1;
  for (Hash &hashi : vh) {
    fl &= ((hashi.get(l1, r1) + hashi.get(l2, r2)) % hashi.mod) == hashi.ht;
  }
  return fl;
}
long long get_lcp(long long i, string &s, string &t, vector<long long> &zf) {
  i += ((long long)(t.size())) + 1;
  return zf[i];
}
signed main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  string s;
  cin >> s;
  string t;
  cin >> t;
  vector<Hash> vh(2, Hash());
  for (Hash &hashi : vh) {
    hashi.build(s, t);
  }
  long long l1, r1, l2, r2;
  long long lcp, len;
  string kek = t + '#' + s;
  vector<long long> zf = z_function(kek);
  for (long long i = 0; i < ((long long)(s.size())); i++) {
    if (i + 2 * ((long long)(t.size())) - 3 < ((long long)(s.size()))) {
      l1 = i;
      r1 = i + ((long long)(t.size())) - 2;
      l2 = i + ((long long)(t.size())) - 1;
      r2 = i + ((long long)(t.size())) - 3;
      if (equal(vh, l1, r1, l2, r2)) {
        cout << l1 + 1 << " " << r1 + 1 << '\n'
             << l2 + 1 << " " << r2 + 1 << '\n';
        return 0;
      }
    }
    lcp = get_lcp(i, s, t, zf);
    {
      len = ((long long)(t.size())) - lcp;
      if (i - len >= 0) {
        long long l1 = i - len;
        long long r1 = i - 1;
        long long l2 = i;
        long long r2 = i + ((long long)(t.size())) - 1;
        if (equal(vh, l1, r1, l2, r2)) {
          cout << l1 + 1 << " " << r1 + 1 << '\n'
               << l2 + 1 << " " << r2 + 1 << '\n';
          return 0;
        }
      }
      len = ((long long)(t.size())) - lcp - 1;
      if (i - len >= 0) {
        long long l1 = i - len;
        long long r1 = i - 1;
        long long l2 = i;
        long long r2 = i + ((long long)(t.size())) - 1;
        if (equal(vh, l1, r1, l2, r2)) {
          cout << l1 + 1 << " " << r1 + 1 << '\n'
               << l2 + 1 << " " << r2 + 1 << '\n';
          return 0;
        }
      }
    }
    {
      len = ((long long)(t.size())) - lcp;
      if (i + ((long long)(t.size())) + len - 1 < ((long long)(s.size()))) {
        long long l1 = i;
        long long r1 = i + ((long long)(t.size())) - 1;
        long long l2 = i + ((long long)(t.size()));
        long long r2 = i + ((long long)(t.size())) + len - 1;
        if (equal(vh, l1, r1, l2, r2)) {
          cout << l1 + 1 << " " << r1 + 1 << '\n'
               << l2 + 1 << " " << r2 + 1 << '\n';
          return 0;
        }
      }
      len = ((long long)(t.size())) - lcp - 1;
      if (i + ((long long)(t.size())) + len - 1 < ((long long)(s.size()))) {
        long long l1 = i;
        long long r1 = i + ((long long)(t.size())) - 1;
        long long l2 = i + ((long long)(t.size()));
        long long r2 = i + ((long long)(t.size())) + len - 1;
        if (equal(vh, l1, r1, l2, r2)) {
          cout << l1 + 1 << " " << r1 + 1 << '\n'
               << l2 + 1 << " " << r2 + 1 << '\n';
          return 0;
        }
      }
    }
  }
}

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
long long xx[4] = {1, 0, 1, -1};
long long yy[4] = {0, 1, 1, 1};
string dir = "RDLU";
string travel = "ENWS";
const long long N = 3e5 + 50, oo = 1e18 + 500;
const long long mod = 1e9 + 7;
const long long M2 = 1000000093, x2 = 27162;
const long long M1 = 1000000087, x1 = 241;
const long double eps = 1e-8, PI = 2 * acos(0.0);
long long bin_pow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
set<string> all;
map<string, string> cannot;
map<long long, set<string>> inp;
map<long long, set<string>> may;
map<string, long long> ind;
long long max_num;
void fill() {
  cannot["white"] = "yellow";
  cannot["yellow"] = "white";
  cannot["green"] = "blue";
  cannot["blue"] = "green";
  cannot["red"] = "orange";
  cannot["orange"] = "red";
  all = {"white", "yellow", "green", "blue", "red", "orange"};
  ind["white"] = 0;
  ind["yellow"] = 0;
  ind["green"] = 1;
  ind["blue"] = 1;
  ind["red"] = 2;
  ind["orange"] = 2;
}
void del(map<long long, set<string>> &mp, long long &key, string &s) {
  if (mp[key].count(s)) mp[key].erase(s);
}
void upd(map<long long, set<string>> &mp, long long key, string &s, string &t) {
  if (!mp.count(key)) mp[key] = all;
  del(mp, key, s);
  del(mp, key, t);
}
void upd_par(long long v) {
  if (!((long long)(inp[v].size()))) return;
  string s = (*inp[v].begin());
  string t = cannot[s];
  if (v > 1) {
    long long par = v / 2;
    upd(may, par, s, t);
  }
}
void upd_son(long long v) {
  if (2 * v > max_num) return;
  for (string s : may[v]) {
    string t = cannot[s];
    upd(may, v << 1, s, t);
    upd(may, v << 1 | 1, s, t);
  }
}
map<long long, long long> cnt;
map<long long, long long> dp[8];
void upd_cnt(long long v) {
  v >>= 1;
  while (v) {
    cnt[v]++;
    v >>= 1;
  }
}
long long popcount(long long mask) {
  long long ret = 0;
  for (long long i = 0; i < 3; i++) {
    ret += (mask & (1 << i)) > 0;
  }
  return ret;
}
long long rec(long long v, long long mask, long long sz) {
  if (sz == 0) return 1;
  if (dp[mask].count(v)) return dp[mask][v];
  long long mult = 2;
  if (may.count(v)) {
    mult = 1;
    mask = (1 << ind[*may[v].begin()]) & mask;
  }
  if (!cnt.count(v)) {
    return bin_pow(4, sz - 1) * popcount(mask) * mult % mod;
  }
  long long ret = 0;
  for (long long i = 0; i < 3; i++) {
    if (mask & (1 << i)) {
      long long new_mask = 7 - (1 << i);
      long long a = rec(v << 1, new_mask, sz >> 1);
      long long b = rec(v << 1 | 1, new_mask, sz >> 1);
      ret = (ret + mult * a * b) % mod;
    }
  }
  dp[mask][v] = ret;
  return ret;
}
signed main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long s, n, k;
    cin >> s >> n >> k;
    if (k > s) {
      cout << "NO" << '\n';
      continue;
    }
    if (k == s) {
      cout << "YES" << '\n';
      continue;
    }
    s += k;
    long long m = s;
    long long div = s / k;
    long long b = (s % k) - 1;
    if (div & 1) {
      m -= k - b - 1;
    } else {
      m -= b + 1;
    }
    m < (2 * n + 1) ? cout << "YES" : cout << "NO";
    cout << '\n';
  }
}

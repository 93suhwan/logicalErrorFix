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
    s += k + 1;
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

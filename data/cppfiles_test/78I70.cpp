#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target_tbl( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const long long mod = 1e9 + 7;
const long long M2 = 1000000093, x2 = 27162;
const long long M1 = 1000000087, x1 = 241;
const long double eps = 1e-7, PI = 2 * acos(0.0);
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
signed main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    vector<long long> c(31);
    for (long long i = 0; i < n; i++) {
      for (long long bit = 0; bit < 31; bit++) {
        c[bit] += ((a[i] & (1ll << bit)) ? 1 : 0);
      }
    }
    long long g = 0;
    for (long long i = 0; i < n; i++) {
      g = gcd(g, c[i]);
    }
    vector<long long> divs;
    for (long long j = 1; j * j <= g; j++) {
      if (g % j == 0) {
        divs.push_back(j);
        divs.push_back(g / j);
      }
    }
    if (g == 0) {
      for (long long i = 1; i <= n; i++) divs.push_back(i);
    }
    sort(divs.begin(), divs.end());
    divs.erase(unique(divs.begin(), divs.end()), divs.end());
    show(divs);
  }
}

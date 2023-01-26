#include <bits/stdc++.h>
#pragma GCC optimize("-O2")
using namespace std;
const int N = 2e5 + 5, MOD = 1e9 + 7;
const long double EPS = 1e-9;
long long binpow(long long a, long long b) {
  long long m = MOD;
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long modInverse(long long a, long long m = MOD) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    set<int> x_val;
    set<int> y_val;
    vector<int> x_ind, y_ind;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      x_val.insert(a);
      x_ind.push_back(a);
    }
    x_ind.push_back(1e9);
    for (int i = 0; i < m; ++i) {
      int a;
      cin >> a;
      y_val.insert(a);
      y_ind.push_back(a);
    }
    y_ind.push_back(1e9);
    set<pair<int, int>> x_only, y_only, both;
    for (int i = 0; i < k; ++i) {
      int x;
      cin >> x;
      int y;
      cin >> y;
      if (x_val.count(x) and y_val.count(y)) {
        both.insert({x, y});
      } else if (x_val.count(x)) {
        x_only.insert({y, x});
      } else {
        y_only.insert({x, y});
      }
    }
    int idx = 0;
    long long ans = 0;
    map<int, int> mp_x;
    long long tot = 0;
    for (auto &pt : x_only) {
      int x = pt.second;
      int y = pt.first;
      if (y > y_ind[idx]) {
        while (y > y_ind[idx]) idx++;
        for (auto &it : mp_x) {
          long long val = it.second;
          long long rem = tot - val;
          ans += (val * rem);
        }
        mp_x.clear();
        tot = 0;
      }
      mp_x[x]++;
      tot++;
    }
    for (auto &it : mp_x) {
      long long val = it.second;
      long long rem = tot - val;
      ans += (val * rem);
    }
    tot = 0;
    map<int, int> mp_y;
    idx = 0;
    for (auto &pt : y_only) {
      int x = pt.first;
      int y = pt.second;
      if (x > x_ind[idx]) {
        while (x > x_ind[idx]) idx++;
        for (auto &it : mp_y) {
          long long val = it.second;
          long long rem = tot - val;
          ans += (val * rem);
        }
        mp_y.clear();
        tot = 0;
      }
      mp_y[y]++;
      tot++;
    }
    for (auto &it : mp_y) {
      long long val = it.second;
      long long rem = tot - val;
      ans += (val * rem);
    }
    cout << ans / 2;
    cout << '\n';
  }
  return 0;
}

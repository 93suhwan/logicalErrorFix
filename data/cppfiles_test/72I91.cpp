#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
const int MAXN = 2e5;
const int LOGN = 18;
const int MOD = (int)1e9 + 7;
void clear() {}
void precalc() {}
void gen_tests() {}
int p[MAXN];
int len[MAXN];
struct item {
  int v, to, c;
};
map<pair<long long, long long>, long long> d;
long long ask(long long x, long long y) {
  if (d.count({x, y})) return d[{x, y}];
  cout << "? " << x << ' ' << y << endl;
  long long dist;
  cin >> dist;
  return d[{x, y}] = dist;
}
long long bin_dist() {
  long long l = 1, r = (int)1e9;
  while (l + 1 < r) {
    long long med = (l + r) >> 1;
    long long c = ask(1, med);
    long long t1 = ask(1, l);
    long long t2 = ask(1, r);
    if (abs(c - t1) != abs(med - l) && abs(c - t2) != abs(r - med)) return c;
    if (abs(c - t1) == abs(med - l)) l = med;
    if (abs(c - t2) == abs(r - med)) r = med;
  }
  long long d = 1e18;
  for (int c = l; c <= r; c++) {
    d = min(d, ask(1, c));
  }
  return d;
}
void solve() {
  long long k = bin_dist();
  long long min_x = k + 1;
  long long min_y = 1 + ask(1, 1) - k;
  long long max_y = (int)1e9 - ask(1, (int)1e9) - k;
  cout << "! " << min_x << ' ' << min_y << ' ' << min_x + (max_y)-min_y << ' '
       << max_y << endl;
}
void multisolve() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  precalc();
  solve();
  return 0;
}

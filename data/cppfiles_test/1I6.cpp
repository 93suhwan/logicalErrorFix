#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:36777216")
using namespace std;
long long mod = 1e9 + 7;
long double eps = 1e-12;
long double pi = acosl(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ifstream in("input.txt");
ofstream out("output.txt");
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uc = unsigned char;
using us = unsigned short;
int x[100020], y[100020];
int n, k;
struct ev {
  double l;
  int type;
  int id;
  ev(double l, int t, int id) : l(l), type(t), id(id){};
  bool operator<(const ev& b) const {
    if (abs(l - b.l) < eps) return type < b.type;
    return l < b.l;
  }
};
bool calc(double r) {
  int add = 0;
  vector<ev> evs;
  for (int i = 0; i < n; i++) {
    double d = x[i] * x[i] + y[i] * y[i];
    if (d < eps) {
      add++;
      continue;
    }
    if (d < 4 * r * r + eps) {
      double phi = atan2(y[i], x[i]);
      double t = acos(sqrt(d) / (eps + 2 * r));
      double lv = phi - t;
      double rv = phi + t;
      evs.push_back(ev(lv - 2 * pi, 0, i));
      evs.push_back(ev(rv - 2 * pi, 1, i));
      evs.push_back(ev(lv, 0, i));
      evs.push_back(ev(rv, 1, i));
      evs.push_back(ev(lv + 2 * pi, 0, i));
      evs.push_back(ev(rv + 2 * pi, 1, i));
      evs.push_back(ev(lv + 4 * pi, 0, i));
      evs.push_back(ev(rv + 4 * pi, 1, i));
    }
  }
  if (add >= k) return 1;
  sort(evs.begin(), evs.end());
  int cur = 0;
  for (auto e : evs) {
    if (e.type == 0) {
      cur++;
      if (cur + add >= k) {
        return 1;
      }
    } else {
      cur--;
    }
  }
  return 0;
}
void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  double l = eps, r = 2e5 + 20;
  for (int i = 0; i < 60; i++) {
    double m = (l + r) / 2;
    if (calc(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r;
}
int main() {
  cout << setprecision(20) << fixed;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  clock_t t1 = clock();
  int t = 1;
  int cs = 1;
  while (t--) {
    solve();
  }
  return 0;
}

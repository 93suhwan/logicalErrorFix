#include <bits/stdc++.h>
using namespace std;
void in() {}
template <typename T, typename... otr_T>
void in(T &t, otr_T &...otr) {
  cin >> t;
  in(otr...);
}
void out(int a, bool ln) { printf("%d%c", a, " \n"[ln]); }
void out(long long a, bool ln) { printf("%lld%c", a, " \n"[ln]); }
void out(double a, int digit, bool ln) {
  printf("%.*f%c", digit, a, " \n"[ln]);
}
const int maxn = 5e5 + 5;
const int maxm = 2e6 + 5;
const int inf = 0x3f3f3f3f;
const double eps = 1e-7;
const long long mod = 998244353;
int n, m;
vector<vector<int>> v;
bool check(int t) {
  bool ret = false;
  vector<bool> vis(n, false);
  for (int i = 0; i < m; ++i) {
    int num = 0;
    for (int j = 0; j < n; ++j) {
      if (v[i][j] >= t) {
        num++;
        vis[j] = true;
      }
    }
    if (num >= 2) ret = true;
  }
  for (int i = 0; i < n; ++i)
    if (!vis[i]) ret = false;
  return ret;
}
int main() {
  int TT;
  cin >> TT;
  for (int TTT = 1; TTT <= TT; ++TTT) {
    in(m, n);
    v.resize(m);
    for (int i = 0; i < m; ++i) {
      v[i].resize(n);
      for (int j = 0; j < n; ++j) {
        in(v[i][j]);
      }
    }
    int l = 1, r = 1e9, mid;
    while (l < r) {
      mid = (l + r + 1) >> 1;
      if (check(mid))
        l = mid;
      else
        r = mid - 1;
    }
    out(l, 1);
  }
}

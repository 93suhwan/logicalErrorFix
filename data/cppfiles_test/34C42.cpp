#include <bits/stdc++.h>
using namespace std;
void canhazfast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T extgcd(T a, T b, T &x, T &y) {
  T x0 = 1, y0 = 0, x1 = 0, y1 = 1;
  while (b) {
    T q = a / b;
    a %= b;
    swap(a, b);
    x0 -= q * x1;
    swap(x0, x1);
    y0 -= q * y1;
    swap(y0, y1);
  }
  x = x0;
  y = y0;
  return a;
}
int ctz(unsigned x) { return __builtin_ctz(x); }
int ctzll(unsigned long long x) { return __builtin_ctzll(x); }
int clz(unsigned x) { return __builtin_clz(x); }
int clzll(unsigned long long x) { return __builtin_clzll(x); }
int popcnt(unsigned x) { return __builtin_popcount(x); }
int popcntll(unsigned long long x) { return __builtin_popcountll(x); }
int bsr(unsigned x) { return 31 ^ clz(x); }
int bsrll(unsigned long long x) { return 63 ^ clzll(x); }
vector<int> q[5000 + 1];
bool res[8192];
int ub[8192];
int main() {
  canhazfast();
  int n;
  vector<int> ans;
  cin >> n;
  for (int i = 1; i <= 5000; ++i) q[i].push_back(0);
  res[0] = true;
  fill_n(ub, 8192, 5000);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (!a) continue;
    for (int v : q[a]) {
      int x = v ^ a;
      if (x == 0) continue;
      res[x] = true;
      for (int j = a + 1; j <= ub[x]; ++j) q[j].push_back(x);
      ub[x] = min(ub[x], a);
    }
    q[a].clear();
  }
  for (int i = 0; i < 8192; ++i) {
    if (res[i]) ans.push_back(i);
  }
  cout << ans.size() << '\n';
  for (int x : ans) cout << x << ' ';
  cout << '\n';
  return 0;
}

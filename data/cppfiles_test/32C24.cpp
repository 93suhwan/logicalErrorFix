#include <bits/stdc++.h>
using namespace std;
mt19937_64 rndGen(chrono::steady_clock::now().time_since_epoch().count());
inline long long read() {
  long long ret;
  scanf("%lld", &ret);
  return ret;
}
template <class T>
inline void cmax(T &a, T b) {
  a = max(a, b);
}
template <class T>
inline void cmin(T &a, T b) {
  a = min(a, b);
}
const long long P = 1e9 + 7;
inline long long pw(long long a, long long x = P - 2) {
  long long ret = 1;
  for (; x; x >>= 1, a = a * a % P)
    if (x & 1) ret = ret * a % P;
  return ret;
}
inline long long wk() {
  int n = read();
  vector<long long> a(n + 1);
  for (int i = (1), __i = (n); i <= __i; ++i) a[i] = read();
  reverse(a.begin() + 1, a.end());
  for (int i = (1), __i = (n); i <= __i; ++i) a[i] += a[i - 1];
  vector<vector<long long>> f(n + 1, vector<long long>(501));
  f[0][0] = 0x3f3f3f3f3f3f3f3fll;
  for (int i = (1), __i = (n); i <= __i; ++i) {
    f[i][0] = 0x3f3f3f3f3f3f3f3fll;
    for (int j = (1), __j = (min(i, 500)); j <= __j; ++j) {
      cmax(f[i][j], f[i - 1][j]);
      if (f[i - j][j - 1] > a[i] - a[i - j]) cmax(f[i][j], a[i] - a[i - j]);
    }
  }
  int ans = 0;
  for (int i = (0), __i = (500); i <= __i; ++i)
    if (f[n][i]) ans = i;
  return ans;
  for (int i = (1), __i = (n); i <= __i; ++i) {
    for (int j = (1), __j = (n); j <= __j; ++j) cout << f[i][j] << ' ';
    cout << endl;
  }
}
int main() {
  for (int _ = (0), ___ = (read()); _ < ___; ++_) {
    cout << wk() << endl;
  }
  return 0;
}

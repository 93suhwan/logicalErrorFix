#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using ll = long long;
using ull = unsigned long long;
using namespace std;
template <class T>
inline void In(T& x) {
  char c;
  T y = 1;
  while (c = getchar(), !isdigit(c) && c != -1) {
    if (c == '-') y = -1;
  }
  x = c - '0';
  while (c = getchar(), isdigit(c)) {
    x = 10 * x + c - '0';
  }
  x *= y;
}
template <class T, class... T_>
inline void In(T& x, T_&... y) {
  In(x), In(y...);
}
int l[1000], r[1000], fl[1000];
int inter(int l1, int r1, int l2, int r2) {
  if (l2 > l1 && l2 < r1 && r2 > l1 && r2 < r1) return 0;
  if ((l2 > r1 || l2 < l1) && (r2 > r1 || r2 < l1)) return 0;
  return 1;
}
void solve() {
  int n, k, a, b;
  fill(fl, fl + 1000, 0);
  In(n, k);
  for (int i = 1; i <= k; i++) {
    In(a, b);
    l[i] = min(a, b);
    r[i] = max(a, b);
    fl[a] = fl[b] = 1;
  }
  vector<int> res;
  for (int i = 1; i <= 2 * n; i++)
    if (!fl[i]) res.push_back(i);
  for (int i = 1; i <= n - k; i++)
    l[k + i] = res[i - 1], r[k + i] = res[i - 1 + n - k];
  int ans = 0;
  for (int i = 1; i <= n; i++) cout << l[i] << ' ' << r[i] << endl;
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) ans += inter(l[i], r[i], l[j], r[j]);
  printf("%d\n", ans);
}
int main() {
  int T;
  In(T);
  while (T--) {
    solve();
  }
}

#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int t, n, x, p, a[200005], b[200005], c[200005], d[200005], ans;
map<int, int> mm;
inline void updatec(int x) {
  for (; x <= n; x += (x & -x)) ++c[x];
  return;
}
inline int getc(int x) {
  int res = 0;
  for (; x; x -= (x & -x)) res += c[x];
  return res;
}
inline void updated(int x) {
  for (; x; x -= (x & -x)) ++d[x];
  return;
}
inline int getd(int x) {
  int res = 0;
  for (; x <= n; x++) res += d[x];
  return res;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> t;
  while (t--) {
    ans = p = 0;
    mm.clear();
    cin >> n;
    memset(c, 0, sizeof c);
    memset(d, 0, sizeof d);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
      if (!mm[b[i]]) mm[b[i]] = ++p;
    }
    for (int i = 1; i <= n; i++) {
      b[i] = mm[a[i]];
      if (getc(b[i] - 1) > getd(b[i] + 1)) {
        ans += getd(b[i] + 1);
      } else {
        ans += getc(b[i] - 1);
      }
      updatec(b[i]);
      updated(b[i]);
    }
    cout << ans << endl;
  }
  return 0;
}

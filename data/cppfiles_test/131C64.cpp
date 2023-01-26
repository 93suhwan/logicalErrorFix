#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
constexpr int Max = 2e5 + 100;
int a[Max], n;
inline int get(const int &x) {
  int i = 1;
  while (i < x) i <<= 1;
  return i - x;
}
inline int dis(int x, int y) {
  int ans = 0;
  for (; x != y; x = get(x), ++ans)
    if (x < y) swap(x, y);
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int s = 1, t = 1;
  for (int i = 1; i <= n; ++i)
    if (dis(a[i], a[s]) > dis(a[s], a[t])) t = i;
  for (int i = 1; i <= n; ++i)
    if (dis(a[i], a[t]) > dis(a[s], a[t])) s = i;
  cout << s << " " << t << " " << dis(a[s], a[t]) << "\n";
  return 0;
}

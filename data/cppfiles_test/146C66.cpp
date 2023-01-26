#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, B = 315;
int n, t, p[N], q[N], Sp[N], l[N], r[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> t;
  for (int i = 1; i <= n; ++i) cin >> p[i];
  for (int i = 1; i <= n; ++i) {
    int a = i;
    for (int j = 1; j <= B; ++j) a = p[a];
    Sp[i] = a, q[p[i]] = i;
  }
  while (t--) {
    int type, x, y;
    cin >> type >> x >> y;
    if (type & 1) {
      swap(p[x], p[y]), q[p[x]] = x, q[p[y]] = y;
      l[0] = r[0] = x;
      for (int i = 1; i <= B; ++i) l[i] = p[l[i - 1]], r[i] = q[r[i - 1]];
      for (int i = 0; i <= B; ++i) Sp[r[i]] = l[B - i];
      l[0] = r[0] = y;
      for (int i = 1; i <= B; ++i) l[i] = p[l[i - 1]], r[i] = q[r[i - 1]];
      for (int i = 0; i <= B; ++i) Sp[r[i]] = l[B - i];
    } else {
      for (int i = 0; i < y / B; ++i) x = Sp[x];
      for (int i = 0; i < y % B; ++i) x = p[x];
      cout << x << endl;
    }
  }
  return 0;
}

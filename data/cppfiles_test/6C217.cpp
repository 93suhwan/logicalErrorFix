#include <bits/stdc++.h>
using namespace std;
int n, m, t, x, y, q, a[200001], ans = 0;
void solve(int tc) {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    a[min(x, y)]++;
  }
  for (int i = 1; i <= n; i++)
    if (!a[i]) ans++;
  cin >> q;
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> x >> y;
      if (!a[min(x, y)]) ans--;
      a[min(x, y)]++;
    } else if (t == 2) {
      cin >> x >> y;
      a[min(x, y)]--;
      if (!a[min(x, y)]) ans++;
    } else {
      cout << ans << "\n";
    }
  }
}
int T = 1;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int TC = 1; TC <= T; TC++) solve(TC);
}

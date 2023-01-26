#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[60];
void solve() {
  ll i, j, w, h, k, f, s, ma = 0;
  cin >> w >> h;
  for (i = 0; i < 4; i++) {
    cin >> k;
    cin >> f;
    for (j = 1; j < k; j++) {
      cin >> s;
    }
    if (i < 2)
      ma = max(ma, (s - f) * h);
    else
      ma = max(ma, (s - f) * w);
  }
  cout << ma << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}

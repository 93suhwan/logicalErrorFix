#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];
  reverse(a.begin(), a.end());
  int now = a[0];
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] > now) {
      ++ans;
      now = a[i];
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}

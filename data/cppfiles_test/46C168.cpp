#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N];
void solve() {
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int min = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    if (min < a[i]) {
      min = a[i];
      ans++;
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

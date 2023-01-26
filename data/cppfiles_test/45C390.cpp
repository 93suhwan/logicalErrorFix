#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int ara[n + 1];
  memset(ara, 0, sizeof(ara));
  for (int i = 1; i <= n; i++) {
    cin >> ara[i];
  }
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    if (ara[i] == 1) {
      if (ara[i - 1] == 1)
        ans += 5;
      else
        ans++;
    }
    if (ara[i] == 0 and ara[i - 1] == 0 and i != 1) {
      cout << -1 << '\n';
      return;
    }
  }
  cout << ans << '\n';
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
void solve(void);
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
void solve(void) {
  cin >> n;
  int i, x, ans;
  for (i = 0; i < n; i++) {
    cin >> x;
    if (!i)
      ans = x;
    else
      ans &= x;
  }
  cout << ans << '\n';
}

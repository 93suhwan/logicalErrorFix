#include <bits/stdc++.h>
using namespace std;
int kek[] = {-1, 1, 2, 4, 5, 7, 8, 10, 11, 14, 16, 17, 19, 20, 22, 25, 26, 28};
void solve() {
  int k;
  cin >> k;
  int ans = (k / 18) * 30 + kek[k % 18];
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}

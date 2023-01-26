#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e18 + 10;
long long T, n, m, ans;
void solve() {
  cin >> n >> m;
  ans = 0;
  m++;
  for (int i = 30; i >= 0; i--) {
    if ((ans ^ n) > m) break;
    if (((1 << i) & (m)))
      if (!(n & (1 << i))) ans += (1 << i);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    solve();
  }
}

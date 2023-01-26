#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string up, down;
  cin >> up >> down;
  long long ans = 0;
  for (long long i = 0; i < n; ++i) {
    if (down[i] == '1') {
      if (up[i] == '0') {
        ans++;
      } else if (i > 0 && up[i - 1] == '1') {
        ans++;
        up[i - 1] = '0';
      } else if (i < n && up[i + 1] == '1') {
        ans++;
        up[i + 1] = '0';
      }
    }
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  while (n--) solve();
  return 0;
}

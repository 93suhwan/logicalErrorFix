#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string a[2];
  cin >> a[0] >> a[1];
  for (long long i = 1; i < n; i++) {
    if (a[0][i - 1] == '0' || a[1][i - 1] == '0') continue;
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}

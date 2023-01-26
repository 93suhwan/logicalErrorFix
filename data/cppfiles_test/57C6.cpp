#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, s, k;
  cin >> s >> n >> k;
  if (s == k)
    cout << "YES" << endl;
  else if (s < k)
    cout << "NO" << endl;
  else if (s >= n + (n / k) * k)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

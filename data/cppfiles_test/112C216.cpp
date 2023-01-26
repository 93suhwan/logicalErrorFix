#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int v[3];
  cin >> v[0] >> v[1] >> v[2];
  long long int m;
  cin >> m;
  sort(v, v + 3, greater<long long int>());
  long long int ab = v[1];
  long long int ac = min(v[0] - ab, v[2]);
  long long int mi = v[0] - ab - ac - 1, mx = v[0] - 1 + v[1] - 1 + v[2] - 1;
  if (!(m >= mi && m <= mx))
    cout << "NO\n";
  else
    cout << "YES\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

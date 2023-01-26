#include <bits/stdc++.h>
using namespace std;
long long int MAX = 1e9 + 7;
long long int mod = 1e9 + 7;
void solve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int res = 0;
  vector<long long int> ar;
  for (long long int x = 0; x < n; x++) ar.push_back(s[x] - '0');
  if (n == 1) {
    cout << ar[0] << endl;
    return;
  }
  for (long long int x = 0; x < n; x++) {
    if (ar[x] == 0) continue;
    if (x < n - 1) res += ar[x] + 1;
    if (x == n - 1) res += ar[x];
  }
  cout << res << endl;
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  for (long long int x = 0; x < t; x++) {
    solve();
  }
  cerr << "[Execution : " << (1.0 * clock()) / CLOCKS_PER_SEC << "s]\n";
  return 0;
}

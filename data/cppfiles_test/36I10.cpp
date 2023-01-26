#include <bits/stdc++.h>
using namespace std;
long long int MAX = 1e9 + 7;
long long int mod = 1e9 + 7;
void solve() {
  long long int n;
  cin >> n;
  string res = "";
  if (n % 2 == 0) {
    for (long long int x = 1; x <= n / 2; x++) res += "a";
    res += "b";
    for (long long int x = 1; x < n / 2; x++) res += "a";
  } else {
    for (long long int x = 1; x <= n / 2; x++) res += "a";
    res += "bc";
    for (long long int x = 1; x < n / 2; x++) res += "a";
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

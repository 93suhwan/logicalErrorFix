#include <bits/stdc++.h>
using namespace std;
void solve() {
  string str;
  cin >> str;
  long long int ans = (str[0] == '0');
  for (long long int i = 1; i < str.size(); i++) {
    if (str[i] == '0' and str[i - 1] == '1') ans++;
  }
  cout << min(2LL, ans) << '\n';
}
signed main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int tt;
  cin >> tt;
  while (tt--) solve();
  cerr << " Execution : " << (1.0 * clock()) / CLOCKS_PER_SEC << "s \n";
  return 0;
}

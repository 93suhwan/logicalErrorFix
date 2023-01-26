#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b;
  cin >> a >> b;
  long long n = a + b;
  vector<long long> ans;
  long long d = abs(a - b) / 2;
  long long add = n & 1 ? 1 : 2;
  for (long long i = d; i <= a + b - d; i += add) ans.push_back(i);
  cout << ans.size() << endl;
  {
    for (auto it : ans) cout << it << " ";
    cout << endl;
  };
}
signed main() {
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

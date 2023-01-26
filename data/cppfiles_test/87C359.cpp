#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < (int)a.size(); i++) cin >> a[i];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, a[i] - i - 1);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}

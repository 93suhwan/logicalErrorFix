#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
void solve() {
  int n, ans = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans = max(ans, a[i] - i - 1);
  }
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

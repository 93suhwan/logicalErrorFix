#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
const int64_t oo = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  a[0] = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      if (a[i - 1])
        ans += 5;
      else
        ans++;
    } else {
      if (i > 1 && (!a[i - 1])) {
        cout << "-1\n";
        return;
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}

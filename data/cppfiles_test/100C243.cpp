#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int inf = 1e9 + 5;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 5];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int del = 0;
    int ans = -inf;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, a[i] - del);
      del += a[i] - del;
    }
    cout << ans << "\n";
  }
  return 0;
}

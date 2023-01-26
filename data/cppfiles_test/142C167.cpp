#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007;
void solve() {
  long long int m, n;
  cin >> m >> n;
  long long int mn[n];
  long long int x = 0;
  memset(mn, -1, sizeof(mn));
  for (long long int i = 0; i < m; i++) {
    long long int a[n];
    for (long long int j = 0; j < n; j++) {
      cin >> a[j];
      mn[j] = max(mn[j], a[j]);
    }
    sort(a, a + n);
    x = max(x, a[n - 2]);
  }
  sort(mn, mn + n);
  long long int res = min(x, mn[0]);
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}

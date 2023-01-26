#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, *a, ans = 0, i, j;
  cin >> n >> m;
  a = new long long[m];
  for (i = 0; i < m; i++) cin >> a[i];
  for (i = 0; i < m - 1; i++) {
    for (j = i + 1; j < m; j++) {
      if (a[i] < a[j]) {
        swap(a[i], a[j]);
        ans++;
      }
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long tcs;
  cin >> tcs;
  while (tcs--) solve();
  return 0;
}

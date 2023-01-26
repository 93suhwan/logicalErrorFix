#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k, i1 = 0, i2 = 0, mn1, mn2;
  cin >> n >> k;
  vector<int> b(n), a(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  a = b;
  mn1 = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (a[i] <= mn1) {
      mn1 = a[i];
      i1 = i;
    }
  }
  a[i1] = INT_MAX;
  mn2 = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (a[i] <= mn2) {
      mn2 = a[i];
      i2 = i;
    }
  }
  long long ans1 = (i1 + 1ll) * (i2 + 1ll) - k * (mn1 | mn2);
  long long ans2 = 1ll * n * (n - 1ll) - k * (b[n - 1] | b[n - 2]);
  cout << max(ans1, ans2) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

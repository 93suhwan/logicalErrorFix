#include <bits/stdc++.h>
using namespace std;
int n, k;
void solve() {
  cin >> n >> k;
  vector<long long> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  long long ans = n * (n - 1) - k * (b[n - 2] | b[n - 1]);
  for (long long i = n - 1; i > 0; i--) {
    for (long long j = i - 1; j >= 0; j--) {
      if ((i + 1) * (j + 1) < ans) break;
      ans = max(ans, (i + 1) * (j + 1) - k * (b[i] | b[j]));
    }
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve();
    cout << '\n';
  }
}

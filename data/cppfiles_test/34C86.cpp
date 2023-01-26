#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  long long int ans = -1e7;
  if (n <= 1000) {
    for (long long int i = 0; i < n; i++) {
      for (long long int j = i + 1; j < n; j++) {
        if (i == j) continue;
        ans = max(ans, (i + 1) * (j + 1) - k * (v[i] | v[j]));
      }
    }
  } else {
    for (long long int i = n - 1; i >= n - 304; i--) {
      for (long long int j = i - 1; j >= n - 304; j--) {
        ans = max(ans, (i + 1) * (j + 1) - k * (v[i] | v[j]));
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
}

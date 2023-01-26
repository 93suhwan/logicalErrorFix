#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i(0); i < n; i++) {
    cin >> arr[i];
  }
  long long ans = arr[0];
  for (long long i(0); i < n; i++) {
    ans = ans & arr[i];
  }
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    solve();
  }
}

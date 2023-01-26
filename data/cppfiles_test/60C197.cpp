#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
void solve() {
  int n;
  cin >> n;
  long long arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  long long ans = arr[0];
  for (int i = 0; i < n; i++) ans = ans & arr[i];
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long arr[n + 5];
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  long long ans = 0, mx = -(int)1e9;
  for (int i = n; i >= max(1ll, n - 200); --i) {
    for (int j = i - 1; j >= max(1ll, n - 200); --j) {
      ans = 1ll * i * j - 1ll * k * (arr[i] | arr[j]);
      mx = max(ans, mx);
    }
  }
  cout << mx << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) solve();
}

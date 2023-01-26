#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long arr[n + 5];
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  long long ans = 0, mx = -(int)1e9;
  for (int i = 1; i <= n - 1; ++i) {
    ans = i * (i + 1) - k * (arr[i] | arr[i + 1]);
    if (ans > mx) mx = ans;
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

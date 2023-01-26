#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  ;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  };
  long long mx = 0;
  for (long long i = 1; i < n; i++) {
    mx = max(a[i] * a[i - 1], mx);
  };
  cout << mx << "\n";
  ;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  ;
  while (T--) solve();
  return 0;
}

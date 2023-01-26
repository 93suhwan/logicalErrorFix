#include <bits/stdc++.h>
using namespace std;
void initcode() {}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  long long s = 0;
  for (long long i = 0; i < n; i++) cin >> a[i], s += a[i];
  if (s % n == 0) {
    cout << 0 << "\n";
  } else
    cout << 1 << "\n";
}
int32_t main() {
  initcode();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

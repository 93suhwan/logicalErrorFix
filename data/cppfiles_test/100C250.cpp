#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long ans = a[0];
  for (int i = 1; i < n; i++) {
    ans = max(ans, a[i] - a[i - 1]);
  }
  cout << ans << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

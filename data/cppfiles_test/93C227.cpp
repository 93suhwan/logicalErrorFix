#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long ans = 0;
  long long comps = 1;
  while (comps < n and k > comps) {
    comps *= 2;
    ans++;
  }
  if (comps >= n)
    cout << ans << "\n";
  else {
    long long temp = ((n - comps) / k) + 1;
    if (comps + (temp - 1) * k >= n)
      cout << ans + temp - 1 << "\n";
    else
      cout << ans + temp << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}

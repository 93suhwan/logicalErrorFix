#include <bits/stdc++.h>
using namespace std;
void fileIO() {}
void solve() {
  long long n, x0;
  cin >> x0 >> n;
  long long ans = 0;
  for (long long i = ((n / 4) * 4) + 1; i <= n; i++) {
    if (i % 4 == 1 || i % 4 == 0)
      ans += i;
    else
      ans -= i;
  }
  if ((x0 % 2) == 0) ans = -ans;
  cout << ans + x0 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i <= (long long)t - 1; i += 1) solve();
  return 0;
}

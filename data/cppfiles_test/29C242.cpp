#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long cnt1 = 0, cnt0 = 0;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    if (x == 1)
      cnt1++;
    else if (x == 0)
      cnt0++;
  }
  long long ans = cnt1;
  for (long long i = 0; i < cnt0; i++) {
    ans *= 2;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long T = 1;
  cin >> T;
  while (T--) solve();
}

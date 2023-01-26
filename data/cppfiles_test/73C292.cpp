#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000000 + 7;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  while (1) {
    bool bol = false;
    if (ans % 2 == 0) {
      for (long long i = 0; i < n - 1; i += 2) {
        if (a[i] > a[i + 1]) swap(a[i], a[i + 1]), bol = true;
      }
    } else {
      for (long long i = 1; i < n - 1; i += 2) {
        if (a[i] > a[i + 1]) swap(a[i], a[i + 1]), bol = true;
      }
    }
    for (long long i = 1; i < n; i++) {
      if (a[i] > a[i + 1]) bol = true;
    }
    if (bol == false)
      break;
    else
      ans++;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

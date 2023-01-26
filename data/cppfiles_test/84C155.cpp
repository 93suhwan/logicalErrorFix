#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, s;
  cin >> n >> s;
  if (n == 1) {
    cout << s << endl;
    return;
  } else if (n == 2) {
    cout << s / n << endl;
    return;
  }
  if (n % 2 == 0) {
    long long ans = s - (n) / 2 + 1;
    long long left = n - (n / 2) + 1;
    cout << s / (left) << endl;
  } else {
    long long ans = s - (n / 2);
    long long left = n - (n / 2);
    cout << s / (left) << endl;
  }
}
int32_t main() {
  ios::sync_with_stdio(!cin.tie(0));
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

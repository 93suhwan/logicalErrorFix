#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, ans = 0;
  cin >> n;
  string s;
  cin >> s;
  for (long long i = 0; i < n; i++) {
    ans += (long long)(s.at(i) - '0');
    if ((long long)(s.at(i) - '0') != 0 && i != n - 1) ans += 1;
  }
  cout << ans << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, ans = 0;
  cin >> n;
  long long x = n % 10;
  if (n > 18) {
    ans += (n / 10 * 25);
  } else if (n == 17 || n == 18)
    ans += 45;
  else if (n == 15 || n == 16)
    ans += 40;
  else if (n == 13 || n == 14)
    ans += 35;
  else if (n == 11 || n == 12)
    ans += 30;
  else if (n == 10 || n == 9)
    ans += 25;
  else if (n == 8 || n == 7)
    ans += 20;
  else if (n <= 6)
    ans += 15;
  if (n > 18 && x > 0) {
    if (x == 9)
      ans += 25;
    else if (x == 8 || x == 7)
      ans += 20;
    else if (x <= 6)
      ans += 15;
  }
  cout << ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}

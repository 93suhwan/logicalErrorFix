#include <bits/stdc++.h>
using namespace std;
long long a, b;
void sol(int tc) {
  cin >> a >> b;
  long long ans = 0, ad = 1;
  while (a || b) {
    long long cur = b % 10;
    b /= 10;
    if (cur < a % 10) {
      cur = (b % 10) * 10 + cur;
      b /= 10;
    }
    if (cur < a % 10 || cur - (a % 10) >= 10) {
      cout << "-1\n";
      return;
    }
    ans = ad * (cur - a % 10) + ans;
    ad *= 10;
    a /= 10;
  }
  if (a)
    cout << "-1\n";
  else
    cout << ans << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) sol(0);
  return 0;
}

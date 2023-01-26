#include <bits/stdc++.h>
using namespace std;
long long a, b;
void sol(int tc) {
  cin >> a >> b;
  long long ans = 0, tmp = 0, f = 0, cur = a % 10, ad = 1;
  a /= 10;
  while (b) {
    long long p = b % 10;
    b /= 10;
    if (f)
      tmp = p * 10 + tmp;
    else
      tmp = p;
    if (tmp - cur >= 10) {
      cout << "-1\n";
      return;
    }
    if (tmp - cur < 0)
      f = 1;
    else {
      f = 0;
      ans = (tmp - cur) * ad + ans;
      ad *= 10;
      cur = a % 10;
      a /= 10;
    }
  }
  if (a || cur)
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

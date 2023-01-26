#include <bits/stdc++.h>
using namespace std;
string dtb(long long a) {
  string s = "";
  for (long long i = 63; i >= 0; i--) {
    if (a & (1LL << i))
      s += '1';
    else
      s += '0';
  }
  return s;
}
void solve() {
  long long a, b;
  cin >> a >> b;
  if (b > a)
    cout << a + 1 << '\n';
  else if (b == a)
    cout << a + 2 << '\n';
  else {
    if (b != 0)
      cout << a << '\n';
    else
      cout << a + 1 << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

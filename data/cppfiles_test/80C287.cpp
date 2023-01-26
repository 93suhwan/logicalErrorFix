#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const long long mod = 998244353;
const long long inf = 1e6 + 20;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = '&' + s;
  int p1 = -1, p2 = -1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      if (p1 == -1) p1 = i;
      p2 = i;
    }
  }
  if (p1 == p2 && p2 == -1) {
    if (n % 2 == 0) {
      cout << 1 << " " << n / 2 << " " << n / 2 + 1 << " " << n << endl;
    } else {
      cout << 1 << " " << n / 2 + 1 << " " << n / 2 + 1 << " " << n << endl;
    }
    return;
  }
  if (p2 > (n + 1) / 2) {
    cout << 1 << " " << p2 << " " << 1 << " " << p2 - 1 << endl;
    return;
  }
  if (n - p1 + 1 > (n + 1) / 2) {
    cout << p2 << " " << n << " " << p2 + 1 << " " << n << endl;
    return;
  }
  if (p1 == p2) {
    cout << 1 << " " << n / 2 + 1 << " " << n / 2 + 1 << " " << n << endl;
    return;
  }
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

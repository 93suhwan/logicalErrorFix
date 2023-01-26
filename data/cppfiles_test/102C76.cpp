#include <bits/stdc++.h>
using namespace std;
const int N = 2e7;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
long long mypower(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long ret = mypower(x, y / 2);
  ret = (ret * ret) % mod;
  if (y % 2) ret = (ret * x) % mod;
  return ret;
}
long long n, m, t;
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    cin >> s;
    long long mx = 0, mn = 1e18;
    long long mx2 = 0, mn2 = 1e18;
    long long x = 1, y = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == 'U') {
        y++;
        y = min(y, n);
      } else if (s[i] == 'D') {
        y--;
        y = max(1ll, y);
      } else if (s[i] == 'L') {
        x++;
        x = min(m, x);
      } else {
        x--;
        x = max(x, 1ll);
      }
    }
    cout << y << " " << x << "\n";
  }
  return 0;
}

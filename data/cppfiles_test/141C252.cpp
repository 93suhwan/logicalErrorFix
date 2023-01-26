#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
void solve() {
  long long int a, s;
  cin >> a >> s;
  vector<long long int> b;
  while (s) {
    long long int x = a % 10;
    long long int y = s % 10;
    if (y >= x) {
      b.push_back(y - x);
    } else {
      s /= 10;
      y += 10 * (s % 10);
      if (y > x && y <= 18 && y >= 10) {
        b.push_back(y - x);
      } else {
        cout << -1 << '\n';
        return;
      }
    }
    s /= 10;
    a /= 10;
  }
  if (a) {
    cout << -1 << '\n';
    return;
  }
  while (b.back() == 0) b.pop_back();
  reverse((b).begin(), (b).end());
  for (long long int x : b) cout << x;
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T = 1;
  cin >> T;
  for (long long int i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}

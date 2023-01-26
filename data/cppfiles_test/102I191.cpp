#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int inf = 1e8;
const int NN = 2e5;
const int mod = 1e9 + 7;
void solve() {
  int n, m;
  cin >> n >> m;
  string s1;
  cin >> s1;
  int X = 0, Y = 0, x = 0, y = 0, l = 0, r = 0, u = 0, d = 0;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == 'U')
      y++;
    else if (s1[i] == 'D')
      y--;
    else if (s1[i] == 'L')
      x--;
    else
      x++;
    if (y >= 0)
      u = max(u, y);
    else if (y < 0)
      d = max(d, abs(y));
    if (x >= 0)
      r = max(r, x);
    else
      l = max(l, abs(x));
    if (r + l < m && u + d < n) {
      X = l + 1, Y = d + 1;
    }
  }
  cout << X << " " << Y << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

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
  int X = 1, Y = 1, x = 0, y = 0, l = 0, r = 0, u = 0, d = 0;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == 'U')
      y++;
    else if (s1[i] == 'D')
      y--;
    else if (s1[i] == 'L')
      x--;
    else
      x++;
    l = min(l, x);
    r = max(r, x);
    u = max(u, y);
    d = min(d, y);
    if (-l + r < m && -d + u < n) {
      X = -d + 1, Y = -l + 1;
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

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long int t = 1, i, j;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    long long int l = 0, r = 0, u = 0, d = 0;
    long long int x = 0, y = 0;
    long long int ansx = 1, ansy = 1;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == 'L')
        y--;
      else if (s[i] == 'R')
        y++;
      else if (s[i] == 'U')
        x--;
      else
        x++;
      if (y < 0 && abs(y) > l) l = abs(y);
      if (y > 0 && y > r) r = y;
      if (x < 0 && abs(x) > u) u = abs(x);
      if (x > 0 && x > d) d = x;
      if (l + r >= m) break;
      if (u + d >= n) break;
      ansy = l + 1;
      ansx = u + 1;
    }
    cout << ansx << " " << ansy << "\n";
  }
  return 0;
}

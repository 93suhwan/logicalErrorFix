#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  long long h = s.size();
  long long x = 0, y = 0, xmin = 0, ymin = 0, xmax = 0, ymax = 0, fx = 1,
            fy = 1;
  for (long long i = 0; i < h; i++) {
    if (s[i] == 'U')
      x--;
    else if (s[i] == 'D')
      x++;
    else if (s[i] == 'L')
      y--;
    else if (s[i] == 'R')
      y++;
    xmax = max(xmax, x);
    xmin = min(xmin, x);
    ymax = max(ymax, y);
    ymin = min(ymin, y);
    if (xmax - xmin >= n) break;
    if (ymax - ymin >= m) break;
    fx = abs(xmin) + 1;
    fy = abs(ymin) + 1;
  }
  cout << fx << " " << fy << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

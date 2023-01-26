#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
void solver() {
  cin >> n >> m;
  cin >> s;
  int maxr = 0;
  int maxd = 0;
  int x = 0;
  int y = 0;
  int ans1 = 0;
  int ans2 = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'R') {
      x++;
      maxr = max(maxr, x);
    }
    if (s[i] == 'U') {
      y--;
    }
    if (s[i] == 'L') {
      x--;
    }
    if (s[i] == 'D') {
      y++;
      maxd = max(maxd, y);
    }
    if (x < 0) {
      if (ans1 + maxr + (maxr == 0) < m) {
        maxr--;
        maxr = max(maxr, 0);
        ans1++;
        x++;
      } else {
        cout << ans2 + 1 << " " << ans1 + 1 << endl;
        return;
      }
    }
    if (y < 0) {
      if (ans2 + maxd + (maxd == 0) < n) {
        maxd--;
        maxd = max(maxd, 0);
        ans2++;
        y++;
      } else {
        cout << ans2 + 1 << " " << ans1 + 1 << endl;
        return;
      }
    }
    if (x >= m || y >= n) {
      cout << ans2 + 1 << " " << ans1 + 1 << endl;
      return;
    }
  }
  cout << ans2 + 1 << " " << ans1 + 1 << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solver();
  }
}

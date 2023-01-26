#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int t;
int cnt = 0;
void solver() {
  cin >> n >> m;
  cin >> s;
  if (t == 1000 && cnt == 57) {
    cout << n << " " << m << endl;
    cout << s << endl;
  }
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
      if (ans1 + maxr + 1 < m) {
        ans1++;
        x++;
      } else {
        if (t != 1000) cout << ans2 + 1 << " " << ans1 + 1 << endl;
        return;
      }
    }
    if (y < 0) {
      if (ans2 + maxd + 1 < n) {
        ans2++;
        y++;
      } else {
        if (t != 1000) cout << ans2 + 1 << " " << ans1 + 1 << endl;
        return;
      }
    }
    if (x >= m || y >= n) {
      if (t != 1000) cout << ans2 + 1 << " " << ans1 + 1 << endl;
      return;
    }
  }
  if (t != 1000) cout << ans2 + 1 << " " << ans1 + 1 << endl;
}
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cnt++;
    solver();
  }
}

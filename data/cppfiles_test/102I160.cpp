#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    long long int x = 0, y = 0;
    long long int Xmin = n, Xmax = 1, Ymin = m, Ymax = 1, i;
    for (i = 0; i < s.length(); i++) {
      if (s[i] == 'L') {
        if (Ymin - 1 <= 0)
          break;
        else
          Ymax += 1;
      }
      if (s[i] == 'R') {
        if (Ymax + 1 > m)
          break;
        else
          Ymin -= 1;
      }
      if (s[i] == 'U') {
        if (Xmin - 1 <= 0)
          break;
        else
          Xmax += 1;
      }
      if (s[i] == 'D') {
        if (Xmax + 1 > n)
          break;
        else
          Xmin -= 1;
      }
    }
    long long int c = 0, x1, y1, c1 = 0;
    x = Xmin, y = Ymax;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'L') {
        if (y - 1 >= 1) {
          y--;
          c++;
        } else
          break;
      }
      if (s[i] == 'R') {
        if (y + 1 <= m) {
          y++;
          c++;
        } else
          break;
      }
      if (s[i] == 'U') {
        if (x - 1 >= 1) {
          x--;
          c++;
        } else
          break;
      }
      if (s[i] == 'D') {
        if (x + 1 <= n) {
          x++;
          c++;
        } else
          break;
      }
    }
    if (c >= c1) {
      c1 = c;
      x1 = Xmin;
      y1 = Ymax;
    }
    c = 0;
    x = Xmax, y = Ymax;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'L') {
        if (y - 1 >= 1) {
          y--;
          c++;
        } else
          break;
      }
      if (s[i] == 'R') {
        if (y + 1 <= m) {
          y++;
          c++;
        } else
          break;
      }
      if (s[i] == 'U') {
        if (x - 1 >= 1) {
          x--;
          c++;
        } else
          break;
      }
      if (s[i] == 'D') {
        if (x + 1 <= n) {
          x++;
          c++;
        } else
          break;
      }
    }
    if (c >= c1) {
      c1 = c;
      x1 = Xmax;
      y1 = Ymax;
    }
    c = 0;
    x = Xmax, y = Ymin;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'L') {
        if (y - 1 >= 1) {
          y--;
          c++;
        } else
          break;
      }
      if (s[i] == 'R') {
        if (y + 1 <= m) {
          y++;
          c++;
        } else
          break;
      }
      if (s[i] == 'U') {
        if (x - 1 >= 1) {
          x--;
          c++;
        } else
          break;
      }
      if (s[i] == 'D') {
        if (x + 1 <= n) {
          x++;
          c++;
        } else
          break;
      }
    }
    if (c >= c1) {
      c1 = c;
      x1 = Xmax;
      y1 = Ymin;
    }
    c = 0;
    x = Xmin, y = Ymin;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'L') {
        if (y - 1 >= 1) {
          y--;
          c++;
        } else
          break;
      }
      if (s[i] == 'R') {
        if (y + 1 <= m) {
          y++;
          c++;
        } else
          break;
      }
      if (s[i] == 'U') {
        if (x - 1 >= 1) {
          x--;
          c++;
        } else
          break;
      }
      if (s[i] == 'D') {
        if (x + 1 <= n) {
          x++;
          c++;
        } else
          break;
      }
    }
    if (c >= c1) {
      c1 = c;
      x1 = Xmin;
      y1 = Ymin;
    }
    cout << x1 << " " << y1;
    cout << "\n";
  }
  return 0;
}

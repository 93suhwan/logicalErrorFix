#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int mod = 998244353;
void solve() {
  int n, m;
  cin >> n >> m;
  int x = 1, y = 1;
  string s1;
  cin >> s1;
  int nowx = 1, nowy = 1;
  bool flag = false;
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] == 'R') {
      nowy++;
      if (nowy > m) {
        nowy--;
        y--;
        if (y == 0) {
          flag = true;
          y++;
        }
      }
    } else if (s1[i] == 'L') {
      nowy--;
      if (nowy <= 0) {
        nowy++;
        y++;
        if (y > m) {
          flag = true;
          y--;
        }
      }
    } else if (s1[i] == 'U') {
      nowx--;
      if (nowx == 0) {
        nowx++;
        x++;
        if (x > n) {
          flag = true;
          x--;
        }
      }
    } else if (s1[i] == 'D') {
      nowx++;
      if (nowx > n) {
        nowx--;
        x--;
        if (x == 0) {
          flag = true;
          x++;
        }
      }
    }
    if (flag) {
      break;
    }
  }
  cout << x << ' ' << y << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

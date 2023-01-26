#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int x = 0;
  int y = 0;
  for (int i = 0; i < 9; i++) {
    if (i % 2 == 0) {
      if (s[i] == '?') {
        x++;
      } else {
        int t = s[i] - '0';
        x += t;
        y += t;
      }
    } else {
      if (s[i] == '?') {
        y--;
      } else {
        int t = s[i] - '0';
        x -= t;
        y -= t;
      }
    }
    if ((i == 5) && (x == 3 || y == -3)) {
      cout << i + 1 << "\n";
      return;
    }
    if ((i == 6) && (x == 3 || y == -2)) {
      cout << i + 1 << "\n";
      return;
    } else if (i == 7 && (x == 2 || y == -2)) {
      cout << i + 1 << "\n";
      return;
    } else if (i == 8 && (x == 2 || y == -1)) {
      cout << i + 1 << "\n";
      return;
    }
  }
  cout << 10 << "\n";
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;
string s;
int isup(string s) { return s == "Up" or s == "Up-Left" or s == "Up-Right"; }
int isdown(string s) {
  return s == "Down" or s == "Down-Right" or s == "Down-Left";
}
void solve() {
  int right = 1;
  int lasti = 0, lastj = 0;
  for (int i = 1; i <= 8; i++) {
    if (right) {
      right = 1 - right;
      int down = 0, up = 0;
      for (int j = 1; j <= 8; j++) {
        if (lasti == i and lastj == j) {
          continue;
        }
        cout << i << " " << j << " " << endl;
        lasti = i;
        lastj = j;
        cin >> s;
        if (s == "Done") {
          return;
        } else if (isdown(s)) {
          i++;
        }
        down += isdown(s);
        up |= isup(s);
      }
      if (down or up) {
        i--;
      }
    } else {
      right = 1 - right;
      int down = 0, up = 0;
      for (int j = 8; j >= 0; j--) {
        if (lasti == i and lastj == j) {
          continue;
        }
        cout << i << " " << j << " " << endl;
        lasti = i;
        lastj = j;
        cin >> s;
        if (s == "Done") {
          return;
        } else if (isdown(s)) {
          i++;
        }
        down += isdown(s);
        up |= isup(s);
      }
      if (down or up) {
        i--;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}

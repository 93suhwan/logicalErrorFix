#include <bits/stdc++.h>
using namespace std;
string s;
int isup(string s) { return s[0] == 'U'; }
int isdown(string s) { return s[0] == 'D'; }
void solve() {
  int right = 1;
  int lasti = 0, lastj = 0;
  for (int i = 1; i <= 8;) {
    if (right) {
      right = 1 - right;
      int vert = 0;
      int went = 0;
      for (int j = 2; j <= 7; j++) {
        if (lasti == i and lastj == j) {
          continue;
        }
        if (i > 8) {
          i = 8;
        }
        cout << i << " " << j << " " << endl;
        lasti = i;
        lastj = j;
        cin >> s;
        if (s == "Done") {
          return;
        }
        if (isdown(s)) {
          vert += isdown(s);
          i++;
          went = 1;
        }
        vert -= isup(s);
      }
      if (vert < 0) {
      } else if (!went) {
        i++;
      }
    } else {
      right = 1 - right;
      int vert = 0;
      int went = 0;
      for (int j = 7; j >= 2; j--) {
        if (lasti == i and lastj == j) {
          continue;
        }
        if (i > 8) {
          i = 8;
        }
        cout << i << " " << j << " " << endl;
        lasti = i;
        lastj = j;
        cin >> s;
        if (s == "Done") {
          return;
        }
        if (isdown(s)) {
          vert += isdown(s);
          i++;
          went = 1;
        }
        vert -= isup(s);
      }
      if (vert < 0) {
      } else if (!went) {
        i++;
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

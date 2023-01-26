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
      int went = 0;
      for (int j = 2; j <= 7 and i <= 8; j++) {
        if (lasti == i and lastj == j) {
          continue;
        }
        cout << i << " " << j << " " << endl;
        lasti = i;
        lastj = j;
        cin >> s;
        if (s == "Done") {
          return;
        }
        if (isdown(s)) {
          i++;
        }
        if (isup(s)) {
          went = 1;
        }
      }
      if (!went) {
        i++;
      }
    } else {
      right = 1 - right;
      int went = 0;
      for (int j = 7; j >= 2 and i <= 8; j--) {
        if (lasti == i and lastj == j) {
          continue;
        }
        cout << i << " " << j << " " << endl;
        lasti = i;
        lastj = j;
        cin >> s;
        if (s == "Done") {
          return;
        }
        if (isdown(s)) {
          i++;
        }
        if (isup(s)) {
          went = 1;
        }
      }
      if (!went) {
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

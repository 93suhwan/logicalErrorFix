#include <bits/stdc++.h>
using namespace std;
string s;
int isup(string s) { return s[0] == 'U'; }
int isdown(string s) { return s[0] == 'D'; }
void solve() {
  int right = 1;
  int lasti = 0, lastj = 0;
  for (int i = 1; i <= 8;) {
    int wentdown = 0, wentup = 0;
    if (right) {
      right = 1 - right;
      for (int j = 1; j <= 8 and i <= 8; j++) {
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
          wentup = 1;
        }
        if (isup(s)) {
          wentdown = 1;
        }
      }
      if (!wentdown and !wentup) {
        i++;
      }
    } else {
      right = 1 - right;
      for (int j = 8; j >= 1 and i <= 8; j--) {
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
          wentup = 1;
        }
        if (isup(s)) {
          wentdown = 1;
        }
      }
      if (!wentdown and !wentup) {
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

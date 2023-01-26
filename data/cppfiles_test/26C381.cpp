#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
void solve() {
  string s;
  cin >> s;
  int cntr1 = 10, cntr2 = 10;
  int wt1 = 0, wt2 = 0;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      if (s[i] == '1' || s[i] == '?') wt1++;
    } else {
      if (s[i] == '1') wt2++;
    }
    int left_t1 = 0, left_t2 = 0;
    for (int j = i + 1; j < 10; j++) {
      if (j % 2 == 0) {
        left_t1++;
      } else {
        left_t2++;
      }
    }
    if (wt1 > wt2 + left_t2) {
      cntr1 = i + 1;
      break;
    }
    if (wt2 > wt1 + left_t1) {
      cntr1 = i + 1;
      break;
    }
  }
  wt1 = 0, wt2 = 0;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      if (s[i] == '1') wt1++;
    } else {
      if (s[i] == '1' || s[i] == '?') wt2++;
    }
    int left_t1 = 0, left_t2 = 0;
    for (int j = i + 1; j < 10; j++) {
      if (j % 2 == 0) {
        left_t1++;
      } else {
        left_t2++;
      }
    }
    if (wt1 > wt2 + left_t2) {
      cntr2 = i + 1;
      break;
    }
    if (wt2 > wt1 + left_t1) {
      cntr2 = i + 1;
      break;
    }
  }
  cout << min(cntr1, cntr2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
    cout << "\n";
  }
  return 0;
}

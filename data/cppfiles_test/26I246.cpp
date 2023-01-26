#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long i, j, n, m, sa = 0, sb = 0, ra = 5, rb = 5;
  string s;
  cin >> s;
  for (i = 0; i < 10; i++) {
    if (s[i] == '1') {
      if ((i + 1) % 2)
        sa++;
      else
        sb++;
    }
  }
  if (sa > sb) {
    sa = 0;
    sb = 0;
    i = 0;
    while (i < 10) {
      if (s[i] == '1') {
        if ((i + 1) % 2) {
          sa++;
          ra--;
        } else {
          sb++;
          rb--;
        }
      } else if (s[i] == '?') {
        if ((i + 1) % 2) {
          s[i] = '1';
          sa++;
          ra--;
        } else {
          s[i] = '0';
          rb--;
        }
      } else if (s[i] == '0') {
        if ((i + 1) % 2) {
          ra--;
        } else {
          rb--;
        }
      }
      if (sa > sb + rb) {
        cout << i + 1 << endl;
        return;
      }
      i++;
    }
  } else {
    sa = 0;
    sb = 0;
    i = 0;
    while (i < 10) {
      if (s[i] == '1') {
        if ((i + 1) % 2) {
          sa++;
          ra--;
        } else {
          sb++;
          rb--;
        }
      } else if (s[i] == '?') {
        if ((i) % 2) {
          s[i] = '1';
          sb++;
          rb--;
        } else {
          s[i] = '0';
          ra--;
        }
      } else if (s[i] == '0') {
        if ((i + 1) % 2) {
          ra--;
        } else {
          rb--;
        }
      }
      if (sb > sa + ra) {
        cout << i + 1 << endl;
        return;
      }
      i++;
    }
  }
  cout << 10 << endl;
}
int32_t main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

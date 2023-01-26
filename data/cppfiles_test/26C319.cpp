#include <bits/stdc++.h>
using namespace std;
const int dif = 1e-9;
void solve() {
  string str;
  cin >> str;
  string xx = str;
  string yy = str;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0 && str[i] == '?') {
      xx[i] = '1';
    } else if (i % 2 == 1 && str[i] == '?') {
      xx[i] = '0';
    } else {
      xx[i] = str[i];
    }
  }
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0 && str[i] == '?') {
      yy[i] = '0';
    } else if (i % 2 == 1 && str[i] == '?') {
      yy[i] = '1';
    } else {
      yy[i] = str[i];
    }
  }
  int a, b;
  int n1 = 0, n2 = 0;
  int n1left = 5, n2left = 5;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      if (xx[i] == '1') {
        n1++;
      }
      n1left--;
    } else if (i % 2 == 1) {
      if (xx[i] == '1') {
        n2++;
      }
      n2left--;
    }
    if (n1 > n2 && (n1 - n2) > n2left) {
      a = i + 1;
      break;
    } else if (n2 > n1 && (n2 - n1) > n1left) {
      a = i + 1;
      break;
    }
    a = i + 1;
  }
  int m1 = 0, m2 = 0;
  int m1left = 5, m2left = 5;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      if (yy[i] == '1') {
        m1++;
      }
      m1left--;
    } else if (i % 2 == 1) {
      if (yy[i] == '1') {
        m2++;
      }
      m2left--;
    }
    if (m1 > m2 && (m1 - m2) > m2left) {
      b = i + 1;
      break;
    } else if (m2 > m1 && (m2 - m1) > m1left) {
      b = i + 1;
      break;
    }
    b = i + 1;
  }
  cout << min(a, b) << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(10);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
}

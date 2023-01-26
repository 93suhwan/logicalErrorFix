#include <bits/stdc++.h>
using namespace std;
int chuyen1(char x) { return (int)x - 48; }
char chuyen2(int x) { return x + 48; }
void solve() {
  string a, s;
  cin >> a >> s;
  bool canfind = true;
  string b = "";
  int n = a.length() - 1;
  int m = s.length() - 1;
  while (m >= 0 && n >= 0) {
    if (s[m] < a[n]) {
      if (m - 1 >= 0) {
        int x = chuyen1(s[m - 1]) * 10 + chuyen1(s[m]) - chuyen1(a[n]);
        if (x >= 10) {
          canfind = false;
          break;
        } else {
          b = chuyen2(x) + b;
          m -= 2;
          n--;
        }
      } else {
        canfind = false;
        break;
      }
    } else {
      b = chuyen2(s[m] - a[n]) + b;
      m--;
      n--;
    }
  }
  if (m > n) {
    for (int i = m; i >= 0; i--) {
      b = s[m] + b;
    }
  } else if (m < n) {
    canfind = false;
  }
  if (canfind) {
    int i = 0;
    while (b[i] == '0') i++;
    while (i < b.length()) {
      cout << b[i];
      i++;
    }
    cout << endl;
  } else
    cout << -1 << endl;
}
int main() {
  int t;
  for (cin >> t; t--;) {
    solve();
  }
}

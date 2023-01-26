#include <bits/stdc++.h>
using namespace std;
int solve(string a) {
  int c1 = 0, c2 = 0;
  for (int i = (0); i < (10); i++) {
    if (i % 2) {
      if (a[i] == '1') c2++;
      int restan = (10 - (i + 1)) / 2;
      if (c2 > c1 + restan || c1 > c2 + restan) {
        return i + 1;
      }
    } else {
      if (a[i] == '1') c1++;
      int restan = (10 - i) / 2;
      if (c2 > c1 + restan - 1 || c1 > c2 + restan) {
        return i + 1;
      }
    }
  }
  return 10;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int T = (0); T < (t); T++) {
    string p;
    cin >> p;
    string a, b;
    a = p, b = p;
    for (int i = (0); i < (10); i++) {
      if (i % 2) {
        if (a[i] == '?') a[i] = '0';
      } else if (a[i] == '?')
        a[i] = '1';
    }
    for (int i = (0); i < (10); i++) {
      if (i % 2) {
        if (b[i] == '?') b[i] = '1';
      } else if (b[i] == '?')
        b[i] = '0';
    }
    cout << min(solve(a), solve(b)) << '\n';
  }
  return 0;
}

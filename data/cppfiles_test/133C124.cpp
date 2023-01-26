#include <bits/stdc++.h>
using namespace std;
string s[1000];
int main() {
  int t, n;
  string a;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n;
    a = "";
    for (int j = 1; j <= n - 2; j++) {
      cin >> s[j];
      if (j > 1) {
        if (s[j][0] == s[j - 1][1]) {
          a += s[j][0];
        }
        if (s[j][0] != s[j - 1][1]) {
          a += s[j - 1][1];
          a += s[j][0];
        }
      }
      if (j == 1) {
        a += s[j][0];
      }
    }
    while (a.size() < n) {
      a += s[n - 2][1];
    }
    cout << a << endl;
  }
}

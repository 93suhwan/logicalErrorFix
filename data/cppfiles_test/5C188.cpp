#include <bits/stdc++.h>
using namespace std;
char s[200041], s2[200041];
int main() {
  int t, p, n, i, rez;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s + 1;
    cin >> s2 + 1;
    rez = 0;
    for (i = 1; i <= n; i++) {
      if (s2[i] == '1') {
        if (s[i] == '0') {
          rez++;
          s[i] = '2';
        } else if (s[i - 1] == '1') {
          rez++;
          s[i - 1] = '2';
        } else if (s[i + 1] == '1') {
          rez++;
          s[i + 1] = '2';
        }
      }
    }
    cout << rez << '\n';
  }
  return 0;
}

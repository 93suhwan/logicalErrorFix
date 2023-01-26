#include <bits/stdc++.h>
using namespace std;
char s[1001];
bool ciur[1001];
int main() {
  int t, gas, i, n, j;
  cin >> t;
  ciur[1] = ciur[0] = 1;
  for (i = 2; i * i <= 1000; i++)
    if (ciur[i] == 0)
      for (j = i * i; j <= 1000; j += i) ciur[j] = 1;
  while (t--) {
    cin >> n;
    cin >> s;
    gas = 0;
    for (i = 0; i < n && !gas; i++) {
      if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' ||
          s[i] == '9') {
        gas = 1;
        cout << 1 << '\n' << s[i] << '\n';
      }
    }
    if (!gas) {
      for (i = 0; i < n && !gas; i++)
        for (j = i + 1; j < n && !gas; j++) {
          if (ciur[(s[i] - '0') * 10 + s[j] - '0']) {
            cout << "2\n";
            cout << (s[i] - '0') * 10 + s[j] - '0' << '\n';
            gas = 1;
          }
        }
      if (!gas) {
        cout << "3\n"
             << (s[1] - '0') * 100 + (s[2] - '0') * 10 + s[3] - '0' << '\n';
      }
    }
  }
  return 0;
}

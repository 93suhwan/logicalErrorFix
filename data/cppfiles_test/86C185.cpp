#include <bits/stdc++.h>
using namespace std;
int main() {
  long long T, k;
  cin >> T;
  for (k = 0; k < T; k++) {
    long long n, i, prv = -1, cnt = 0;
    string s[2];
    cin >> n >> s[0] >> s[1];
    for (i = 0; i < n; i++) {
      if (s[0][i] != s[1][i]) {
        cnt += 2;
        prv = -1;
      } else {
        if (s[0][i] == '0') cnt++;
        if (prv == 0 && s[0][i] == '1') {
          prv = -1;
          cnt++;
        } else if (prv == 1 && s[0][i] == '0') {
          prv = -1;
          cnt++;
        } else {
          if (s[0][i] == '1')
            prv = 1;
          else
            prv = 0;
        }
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
char s[70][70];
int main(void) {
  int t;
  cin >> t;
  long long x = 1;
  for (int i = 0; i < 64; i++) {
    long long tmp = x, tmp2 = x, len = 0;
    while (tmp2 > 0) {
      len++;
      tmp2 /= 10;
    }
    while (tmp > 0) {
      s[i][len - 1] = char(tmp % 10 + 48);
      tmp /= 10;
      len--;
    }
    x *= 2;
  }
  while (t--) {
    char ss[64];
    cin >> ss;
    int minx = 1e9 + 10;
    for (int i = 0; i < 63; i++) {
      int len = strlen(s[i]);
      int cnt1 = len, cnt2 = 0;
      int k = 0;
      for (int j = 0; j < strlen(ss); j++) {
        if (s[i][k] == ss[j]) {
          k++;
          cnt1--;
        } else {
          cnt2++;
        }
        if (k >= len) {
          cnt2 += strlen(ss) - j - 1;
          break;
        }
      }
      cout << cnt1 << " " << cnt2 << endl;
      int sum = cnt1 + cnt2;
      minx = min(sum, minx);
    }
    cout << minx << endl;
  }
  return 0;
}

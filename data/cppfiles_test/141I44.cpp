#include <bits/stdc++.h>
using namespace std;
long long t, lena, lens, i, j;
char a[25], s[25];
int main() {
  cin >> t;
  for (; t--;) {
    int aa[25] = {0}, ss[25] = {0};
    int bb[25] = {0};
    scanf("%s%s", a, s);
    lena = strlen(a);
    lens = strlen(s);
    for (i = lena - 1; i >= 0; i--) aa[lena - i] = a[i] - '0';
    for (i = lens - 1; i >= 0; i--) ss[lens - i] = s[i] - '0';
    int p = 1, q = 1;
    for (j = i = 1; i <= lens;) {
      if (ss[i] < aa[j]) {
        if (ss[i + 1] == 1) {
          bb[p] = ss[i] + 10 - aa[j];
          p++;
          i += 2;
          j++;
        } else {
          cout << -1 << endl;
          q = 0;
          break;
        }
      } else {
        bb[p] = ss[i] - aa[j];
        p++;
        j++;
        i++;
      }
    }
    if (q == 1 && aa[j] != 0 && ss[i] == 0) {
      cout << -1 << endl;
      q = 0;
    }
    if (q == 1) {
      for (i = p - 1; i > 1; i--) {
        if (bb[p - 1] != 0) {
          cout << bb[p - 1];
          p--;
          break;
        } else
          p--;
      }
      for (i = p - 1; i >= 1; i--) cout << bb[i];
      cout << endl;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int N = 5e5 + 10;
int a[N], n, m;
signed main() {
  int t = 1;
  scanf("%lld", &t);
  while (t--) {
    string aa, ss;
    cin >> aa >> ss;
    n = aa.length();
    m = ss.length();
    int cnt = 0;
    int j = n - 1;
    int f = 1;
    for (int i = m - 1; i >= 0; i--) {
      if (j < 0) {
        a[++cnt] = ss[i] - '0';
      } else {
        if (ss[i] >= aa[j])
          a[++cnt] = ss[i] - aa[j--];
        else if (ss[i - 1] != '1') {
          f = 0;
          break;
        } else {
          a[++cnt] = ss[i--] - aa[j--] + 10;
        }
      }
    }
    if (j != -1) f = 0;
    if (f == 0)
      cout << "-1\n";
    else {
      while (cnt >= 1 and a[cnt] == 0) {
        cnt -= 1;
      }
      for (int i = cnt; i >= 1; i--) {
        cout << a[i];
      }
      cout << endl;
    }
  }
}

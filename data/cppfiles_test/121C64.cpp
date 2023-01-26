#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10, inf = 0x3f3f3f3f3f3f3f3f, mod = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cntsame1 = 0, cntsame0 = 0, cntdiff1 = 0, cntdiff0 = 0;
    for (long long i = 0; i <= n - 1; ++i) {
      if (s[i] == t[i]) {
        if (s[i] == '1')
          cntsame1++;
        else
          cntsame0++;
      } else {
        if (s[i] == '1')
          cntdiff1++;
        else
          cntdiff0++;
      }
    }
    int cntdiff = cntdiff0 + cntdiff1, cntsame = cntsame0 + cntsame1;
    if (cntdiff % 2 == 1 && cntsame % 2 == 0)
      cout << -1 << endl;
    else {
      if (cntsame0 == cntsame1 - 1 && cntdiff1 == cntdiff0)
        cout << min(cntdiff, cntsame) << endl;
      else if (cntdiff1 == cntdiff0)
        cout << cntdiff << endl;
      else if (cntsame0 == cntsame1 - 1)
        cout << cntsame << endl;
      else
        cout << -1 << endl;
    }
  }
  fflush(stdin);
  getchar();
  return 0;
}

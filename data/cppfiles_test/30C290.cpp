#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
long long mod = 1000000007LL;
long long mod2 = 998244353LL;
int t, n, m, h;
long long k;
int q;
int a[2000];
string s;
int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    cin >> s;
    int tot = n + 1;
    for (int c = 0; c < 26; ++c) {
      int l = 0, r = n - 1;
      int cnt = 0;
      bool ok = true;
      while (l < r) {
        if (s[l] == s[r]) {
          l++;
          r--;
        } else {
          if (s[l] == 'a' + c) {
            l++;
            cnt++;
          } else if (s[r] == 'a' + c) {
            r--;
            cnt++;
          } else {
            ok = false;
            break;
          }
        }
      }
      if (ok) {
        tot = min(tot, cnt);
      }
    }
    printf("%d\n", tot <= n ? tot : -1);
  }
  return 0;
}

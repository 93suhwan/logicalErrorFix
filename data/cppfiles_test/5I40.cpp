#include <bits/stdc++.h>
using namespace std;
const long long N = 100 * 10000 + 9;
void HakunaMatata() {
  long long n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  long long ans = 0;
  for (long long i = 0; i < (long long)s.size(); i++) {
    if (s[i] == '0' and t[i] == '1') {
      ans++;
      continue;
    }
    if (i == 0 and s[i] == '1') {
      if (t[i + 1] == '1') {
        ans++;
        t[i + 1] = '0';
      }
    } else if (i == n - 1 and s[i] == '1') {
      if (t[i - 1] == '1') {
        t[i + 1] = '0';
        ans++;
      }
    } else {
      if (t[i - 1] and s[i] == '1') {
        if (t[i - 1] == '1') {
          ans++;
          t[i - 1] = '0';
        } else if (t[i + 1] == '1') {
          ans++;
          t[i + 1] = '0';
        }
      }
    }
  }
  cout << ans << '\n';
  return;
}
signed main() {
  long long ___T;
  scanf("%lld", &___T);
  for (long long cs = 1; cs <= ___T; cs++) HakunaMatata();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
long long f[1000005];
int main() {
  long long tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    for (long long i = 0; i < s.size(); i++) f[s[i]] = i;
    long long ans = 0;
    for (long long i = 1; i < t.size(); i++) ans += abs(f[t[i - 1]] - f[t[i]]);
    printf("%lld\n", ans);
  }
  return 0;
}

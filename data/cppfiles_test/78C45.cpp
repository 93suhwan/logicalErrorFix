#include <bits/stdc++.h>
using namespace std;
double PI = 3.14159265359;
long long inf = 1000000000000000007;
long long mod = 1000000007;
long long mod1 = 998244353;
const bool multi = 1;
long long a[200007];
long long ile[30];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt;
  if (multi)
    cin >> tt;
  else
    tt = 1;
  while (tt--) {
    long long n;
    cin >> n;
    memset(ile, 0, sizeof ile);
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      for (long long j = 29; j >= 0; j--) ile[j] += (a[i] & (1 << j)) > 0;
    }
    for (long long i = 1; i <= n; i++) {
      bool ok = 1;
      for (long long j = 29; j >= 0; j--)
        if (ile[j] % i != 0) ok = 0;
      if (ok) cout << i << " ";
    }
    cout << '\n';
  }
  return 0;
}

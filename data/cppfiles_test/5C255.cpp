#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const double PI = 3.141592653589793238463;
const int INF = 0x3f3f3f3f;
const int INFS = 1000000001;
const long long LLINF = 9223372036854775807;
const long long M = 1000000007;
const double EPS = 1e-8;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      if (a[i] == '0' && b[i] == '1') {
        ++ans;
        b[i] = '0';
      }
    }
    for (long long i = 0; i < n - 1; i++) {
      if (b[i] == '1' && a[i + 1] == '1') {
        ++ans;
        b[i] = '0';
        a[i + 1] = '0';
      }
      if (b[i + 1] == '1' && a[i] == '1') {
        ++ans;
        b[i + 1] = '0';
        a[i] = '0';
      }
    }
    cout << ans << "\n";
  }
  return 0;
}

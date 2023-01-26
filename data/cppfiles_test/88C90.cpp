#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
const unsigned int mod = 998244353;
const int MAXN = 1e5 + 55;
const long long int MAXD = 1e14;
const long long int INF = 1e18;
const long long int NINF = INF * (-1);
const int INTINF = 1e8;
const int INTNINF = INTINF * (-1);
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = ((res) % mod * (a) % mod) % mod;
    a = ((a) % mod * (a) % mod) % mod;
    b >>= 1;
  }
  return res;
}
void testmetal() {
  long long int n;
  cin >> n;
  ;
  long long int m;
  cin >> m;
  ;
  vector<pair<long long int, long long int>> a(n * m);
  long long int cnt = 0;
  for (long long int i = 0; i < n * m; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = i * m + 1; j < (i + 1) * m; j++) {
      long long int temp = 0;
      for (long long int k = i * m; k < j && a[k].first != a[j].first; k++) {
        if (a[k].second < a[j].second) {
          temp++;
        }
      }
      ans += temp;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    testmetal();
  }
  return 0;
}

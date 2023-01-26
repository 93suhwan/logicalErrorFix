#include <bits/stdc++.h>
using namespace std;
long long int ksm(long long int a, long long int b, long long int mod) {
  long long int ans = 1;
  while (b) {
    if (b & 1) {
      ans = (a % mod * ans % mod) % mod;
    }
    b >>= 1;
    a = (a % mod * a % mod) % mod;
  }
  return ans;
}
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
const long long int mod = 1e9 + 7;
const int maxn = 2e5 + 10;
const int maxm = 2e3 + 50;
const double eps = 1e-8;
const long long int inf = 0x3f3f3f3f;
const long long int lnf = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1);
int n, m;
long long int a[maxn];
string s;
void sove() {
  long long int mi = inf;
  long long int ma = 0;
  cin >> n;
  long long int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i > 1) ans = max(ans, a[i] * a[i - 1]);
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int T;
  cin >> T;
  while (T--) {
    sove();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj;
int e1, e2;
int N, M;
long long int gcd(long long int a, long long int b);
long long int lcm(long long int a, long long int b);
long long int CEIL(long long int a, long long int b);
long long int power_mod(long long int a, long long int b, long long int mod);
vector<long long int> powers;
void pre() {
  long long int p = 1;
  while (p <= 1e9) {
    powers.push_back(p);
    p *= 2;
  }
}
void solve(long long int input) {
  long long n, k;
  cin >> n >> k;
  long long p = 1;
  long long int z = 0;
  while (p <= k) p *= 2, ++z;
  if (p == k) {
    cout << power_mod(n, z, 1e9 + 7) << "\n";
    return;
  }
  long long ans = 0;
  const long long int mod = 1e9 + 7;
  long long int pos;
  while (1) {
    pos = upper_bound(powers.begin(), powers.end(), k) - powers.begin();
    pos--;
    (ans += power_mod(n, pos, mod)) %= mod;
    k -= powers[pos];
    if (k <= 0) break;
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int x = 1;
  pre();
  cin >> x;
  for (long long int i = 1; i <= x; i++) {
    solve(i);
  }
  return 0;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
long long int CEIL(long long int a, long long int b) { return (a + b - 1) / b; }
long long int power_mod(long long int x, long long int y, long long int mod) {
  long long int res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}

#include <bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
const long long int nmax = 2 * 1e3 + 10;
vector<pair<long long int, long long int> > dir{
    {0, -1}, {-1, 0}, {0, 1}, {1, 0}};
long long int mod_sub(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long int mod_add(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long int mod_mul(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
void sieve(vector<long long int>& arr, long long int n) {
  arr[0] = -1;
  arr[1] = -1;
  for (long long int i = 2; (i * i) <= n; i++) {
    if (arr[i] != -1) {
      for (long long int j = i * i; j <= n; j += i) arr[j] = -1;
    }
  }
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int mod_exp(long long int a, long long int b, long long int c) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  long long int smallans;
  if (b % 2 == 0) {
    smallans = mod_exp(a, b / 2, c);
    return mod_mul(smallans, smallans, c);
  } else {
    smallans = mod_exp(a, b - 1, c);
    return mod_mul(a, smallans, c);
  }
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n + 1);
  for (long long int i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  vector<long long int> dp1(n + 2);
  dp1[0] = 1;
  vector<long long int> dp2(n + 2);
  for (long long int i = 1; i < n + 1; i++) {
    if (a[i] > 0) {
      dp2[a[i] - 1] = (dp1[a[i] - 1] % mod + (2 * dp2[a[i] - 1]) % mod) % mod;
    }
    dp1[a[i] + 1] = (dp1[a[i]] % mod + (2 * dp1[a[i] + 1]) % mod) % mod;
    dp2[a[i] + 1] = (2 * dp2[a[i] + 1]) % mod;
  }
  long long int sum = 0;
  for (long long int i = 0; i < n + 1; i++) {
    sum = (sum % mod + dp1[i] % mod + dp2[i] % mod) % mod;
  }
  cout << ((sum - 1) % mod + mod) % mod;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}

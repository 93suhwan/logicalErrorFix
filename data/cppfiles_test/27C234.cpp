#include <bits/stdc++.h>
const long long int MOD = 1000000007;
const long long int MOD1 = 998244353;
const long long int INF = 1e18;
const double pi = 3.14159265358979323846;
using namespace std;
long long int zero = 0;
long long int EXP(long long int a, long long int b) {
  long long int result = 1;
  while (b > 0) {
    if (b & 1) result = result * a;
    a = a * a;
    b >>= 1;
  }
  return result;
}
long long int mod_exponent(long long int a, long long int b,
                           long long int mod) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
long long int mod_inv_prime(long long int a, long long int b) {
  return mod_exponent(a, b - 2, b);
}
vector<long long int> SIEVE(long long int n) {
  bool mark[n + 1];
  vector<long long int> ans;
  for (long long int i = 0; i < n + 1; i++) mark[i] = true;
  for (long long int p = 2; p * p <= n; p++) {
    if (mark[p] == true) {
      for (long long int i = p * p; i <= n; i += p) mark[i] = false;
    }
  }
  for (long long int i = 2; i < n + 1; i++) {
    if (mark[i] == true) {
      ans.push_back(i);
    }
  }
  return ans;
}
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  k -= 2;
  if (m < n - 1 || k < 0) {
    cout << "NO\n";
    return;
  }
  if (k == 0) {
    if (n == 1 && m == 0) {
      cout << "YES\n";
      return;
    } else {
      cout << "NO\n";
      return;
    }
  }
  if (k == 1) {
    long long int edges = (n * (n - 1)) / 2;
    if (edges == m) {
      cout << "YES\n";
      return;
    } else {
      cout << "NO\n";
      return;
    }
  } else {
    long long int edges = (n * (n - 1)) / 2;
    if (m <= edges) {
      cout << "YES\n";
      return;
    } else {
      cout << "NO\n";
      return;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

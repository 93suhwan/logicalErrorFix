#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long exp(long long x, long long y) {
  x %= 1000000007;
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % 1000000007;
    x = x * x % 1000000007;
    y >>= 1;
  }
  return res;
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; ++i) (res *= i) %= 1000000007;
  return res;
}
bool isprime(long long n) {
  if (n <= 1) return 0;
  for (long long i = 2; i * i <= n; ++i)
    if (n % i == 0) return 0;
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  vector<int> col(m);
  for (int i = 0; i < m - 1; ++i)
    for (int j = 1; j < n; ++j) {
      if (v[j][i] == 'X' && v[j - 1][i + 1] == 'X') {
        col[i] = 1;
      }
    }
  for (int j = 1; j < m; ++j) col[j] += col[j - 1];
  int q;
  cin >> q;
  while (q--) {
    int x1, x2;
    cin >> x1 >> x2;
    if (x2 - x1 + 1 == 1) {
      cout << "YES\n";
      continue;
    }
    --x1, --x2;
    if (col[x2 - 1] - (x1 - 1 >= 0 ? col[x1 - 1] : 0) > 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}

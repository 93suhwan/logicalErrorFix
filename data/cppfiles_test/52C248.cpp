#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long mod = 1e9 + 7;
const long long base = 31;
long long power(long long a, long long n, long long mod) {
  if (n == 0)
    return 1;
  else {
    long long temp = power(a, n / 2, mod) % mod;
    temp = (temp * temp) % mod;
    if (n % 2 == 1)
      return (a * temp) % mod;
    else
      return temp;
  }
}
void fre() {}
clock_t start = clock();
double timecomplexity;
int n, k;
long long ans = 0;
void solve() {
  cin >> n >> k;
  ans = 0;
  for (int i = 0; i <= 31; i++)
    if (((k >> i) & 1) == 1) {
      ans += power(n, i, mod);
      ans %= mod;
    }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}

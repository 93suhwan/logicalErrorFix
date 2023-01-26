#include <bits/stdc++.h>
using namespace std;
vector<int64_t> fact_table(int n, int64_t m) {
  vector<int64_t> fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % m;
  return fact;
}
uint64_t fast_exp(uint64_t a, uint64_t b, uint64_t m) {
  uint64_t ans = 1;
  while (b >= 1) {
    if (b % 2) ans = ans * a % m;
    b /= 2;
    a = a * a % m;
  }
  return ans;
}
int64_t inv(int64_t x, int64_t m) { return fast_exp(x, m - 2, m); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  const int64_t MOD = 1e9 + 7;
  vector<int64_t> fact = fact_table(2 * 1e5 + 1, MOD);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (fact[n * 2] * inv(2, MOD) % MOD) << endl;
  }
  return 0;
}

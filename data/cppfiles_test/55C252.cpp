#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 1e6 + 10;
long long qp(long long first, long long second) {
  long long res = first, ans = 1;
  while (second) {
    if (second & 1) ans = ans * res % MOD;
    res = res * res % MOD;
    second >>= 1;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int k;
  cin >> k;
  long long res = 2, sum = 6;
  for (int i = 2; i <= k; ++i) {
    sum = (sum * qp(4, res)) % MOD;
    res <<= 1;
  }
  cout << sum << '\n';
  return 0;
}

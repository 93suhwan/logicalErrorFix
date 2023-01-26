#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
using namespace std;
using namespace chrono;
const int MOD = (1e9 + 7);
long long power(long long a, long long b) {
  long long res = 1;
  a = a % MOD;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % MOD;
      b--;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, i, j, k, f;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cin >> n;
    cout << n / 10 + bool(n % 10 == 9) << "\n";
  }
  return 0;
}

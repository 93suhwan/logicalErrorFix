#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, N = 222222;
signed main() {
  long long q;
  cin >> q;
  vector<long long> fact(N);
  fact[2] = 1;
  for (long long i = 3; i < N; ++i) fact[i] = fact[i - 1] * i % mod;
  while (q--) {
    long long n;
    cin >> n;
    n *= 2;
    cout << fact[n] << '\n';
  }
}

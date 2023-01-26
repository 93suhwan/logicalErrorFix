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
    vector<long long> v;
    long long temp = n;
    while (temp) v.push_back(temp % 10), temp /= 10;
    reverse(v.begin(), v.end());
    long long l = v.size();
    long long n1 = 0, n2 = 0;
    for (i = 0; i < l; i += 2) n1 = n1 * 10 + v[i];
    for (i = 1; i < l; i += 2) n2 = n2 * 10 + v[i];
    long long ans = 0;
    cout << (n1 + 1) * (n2 + 1) - 2 << "\n";
  }
  return 0;
}

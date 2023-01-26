#include <bits/stdc++.h>
using namespace std;
namespace PhiFunction {
long long phi(long long n) {
  long long result = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  }
  if (n > 1) result -= result / n;
  return result;
}
vector<long long> phi_1_to_n(long long n) {
  vector<long long> phi(n + 1);
  phi[0] = 0;
  phi[1] = 1;
  for (long long i = 2; i <= n; i++) phi[i] = i;
  for (long long i = 2; i <= n; i++) {
    if (phi[i] == i) {
      for (long long j = i; j <= n; j += i) phi[j] -= phi[j] / i;
    }
  }
  return phi;
}
}  // namespace PhiFunction
const long long MAX = 1e5 + 5, MOD = 1e9 + 7;
long long n, a[MAX];
vector<long long> g[MAX];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<long long> phi = PhiFunction::phi_1_to_n(100000);
  for (long long i = 1; i <= 1e5; i++)
    for (long long j = i; j <= 1e5; j += i) g[j].push_back(i);
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long rs = 0;
  for (long long d1 = 1; d1 <= n; d1++) {
    unordered_map<long long, long long> C;
    for (long long p = d1; p <= n; p += d1)
      for (long long d2 : g[a[p]]) C[d2]++;
    for (auto tmp : C) {
      long long d2 = tmp.first;
      long long val = tmp.second * tmp.second % MOD;
      rs = (rs + phi[d1] * phi[d2] % MOD * val) % MOD;
    }
  }
  cout << rs;
}

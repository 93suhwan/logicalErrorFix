#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 9;
const int P = 998244353;
long long fact[N], Inv[N], inv_fact[N];
void find_inv() {
  Inv[0] = 0;
  Inv[1] = 1;
  for (int i = 2; i < N; ++i) Inv[i] = (P - P / i) * Inv[P % i] % P;
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = fact[i - 1] * i % P;
    inv_fact[i] = inv_fact[i - 1] * Inv[i] % P;
  }
}
long long C(int n, int m) {
  return fact[n] * inv_fact[m] % P * inv_fact[n - m] % P;
}
void solve() {
  int n;
  scanf("%d", &n);
  map<int, int> mp;
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    ++mp[a];
  }
  if ((int)mp.size() == 1) {
    printf("%lld\n", fact[n]);
  } else if (mp.rbegin()->second >= 2) {
    printf("%lld\n", fact[n]);
  } else if (mp.rbegin()->first - (++mp.rbegin())->first == 1) {
    int x = (++mp.rbegin())->second;
    printf("%lld\n",
           (fact[x + 1] - fact[x] + P) * C(n, x + 1) % P * fact[n - x - 1] % P);
  } else {
    printf("0\n");
  }
}
int main() {
  find_inv();
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}

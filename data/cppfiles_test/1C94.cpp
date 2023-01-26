#include <bits/stdc++.h>
using namespace std;
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;
const long double PI = 3.14159265358979323846;
const long double E = 2.718281828459;
long long MOD = 1e9 + 7;
long long M(long long n) { return (n % MOD + MOD) % MOD; }
long long pow2(long long n) { return 1ll << n; }
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
long long getInv(long long a, long long p) {
  return (a == 1 ? 1 : (1 - p * getInv(p % a, a)) / a + p);
}
const long long FAC_SIZE = 1e4 + 3;
long long fac[FAC_SIZE], inv[FAC_SIZE];
void initFac(long long sz) {
  fac[0] = 1, inv[0] = 1;
  for (int(i) = (1); (i) <= (sz - 1); (i)++) fac[i] = fac[i - 1] * i % MOD;
  inv[FAC_SIZE - 1] = getInv(fac[FAC_SIZE - 1], MOD);
  for (int(i) = (sz - 2); (i) >= (1); (i)--)
    inv[i] = inv[i + 1] * (i + 1) % MOD;
}
long long comb(long long x, long long y) {
  if (x < y) return 0;
  long long ret = 1;
  for (int(i) = (1); (i) <= (y); (i)++) {
    ret = ret * x / i;
    ;
    x--;
  };
  return ret;
}
int main(int argn, char **argv) {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  initFac(FAC_SIZE);
  int T = 1;
  for (int(I) = (0); (I) <= ((T)-1); (I)++) {
    long long n;
    cin >> n;
    vector<vector<long long>> cnt(2, vector<long long>(2, 0));
    for (int(i) = (0); (i) <= ((n)-1); (i)++) {
      long long x, y;
      cin >> x >> y;
      x >>= 1, y >>= 1;
      cnt[x & 1][y & 1]++;
    };
    ;
    long long ans = 0;
    for (int(i) = (0); (i) <= ((2) - 1); (i)++)
      for (int(j) = (0); (j) <= ((2) - 1); (j)++) {
        ans += comb(cnt[i][j], 3);
        ans += comb(cnt[i][j], 2) * (n - cnt[i][j]);
      };
    cout << ans << endl;
  }
  return 0;
}

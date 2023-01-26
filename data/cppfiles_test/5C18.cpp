#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
long long n, k;
long long a[100050];
long long cnt[100050];
map<long long, long long> dict;
long long f[100050];
long long fac[100000 + 50], ifac[100000 + 50];
long long pwk[100050];
long long ksm(long long a, long long x = M - 2) {
  long long ret = 1;
  for (; x; x >>= 1, a = a * a % M)
    if (x & 1) ret = ret * a % M;
  return ret;
}
long long C(long long n, long long m) {
  if (m < 0 || m > n) return 0;
  return fac[n] * ifac[m] % M * ifac[n - m] % M;
}
void prepare() {
  fac[0] = 1;
  for (int i = 1; i <= 100000; i++) fac[i] = fac[i - 1] * i % M;
  ifac[100000] = ksm(fac[100000]);
  for (int i = 100000 - 1; i >= 0; i--) ifac[i] = ifac[i + 1] * (i + 1) % M;
}
int main() {
  ios_base::sync_with_stdio(false);
  prepare();
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dict[a[i]]++;
  }
  cnt[0] = k;
  for (auto y : dict)
    if (y.first != -1) cnt[y.second]++, cnt[0]--;
  int r = 0;
  if (dict.find(-1) != dict.end()) r = dict[-1];
  for (int i = 1; i < n; i++) {
    f[i + 1] = ksm(M + i - n) *
               ((k - 1) * i % M * f[i - 1] % M +
                ((M + 2 - k) * i % M - n + M) * f[i] % M + i * k % M) %
               M;
  }
  long long invpwkr = ksm(ksm(k, r));
  pwk[0] = 1;
  for (int i = 1; i <= n; i++) pwk[i] = pwk[i - 1] * (k - 1) % M;
  long long ans = (M - (f[0] * (k - 1) + f[n]) % M) % M;
  for (int i = 0; i <= n; i++)
    if (cnt[i] != 0) {
      for (int j = 0; j <= r; j++)
        ans = (ans +
               C(r, j) * f[i + j] % M * cnt[i] % M * invpwkr % M * pwk[r - j]) %
              M;
    }
  cout << ans << '\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int MAXN = 2e5 + 2;
long long fac[MAXN];
long long C(long long n, long long k) {
  if (!k || n == k) return 1;
  long long ans =
      (fac[n] % mod) / (((fac[n - k] % mod) * (fac[k] % mod)) % mod) % mod;
  return ans;
}
void run_case() {
  long long n, k;
  cin >> n >> k;
  if (k < 1) {
    cout << 1 << endl;
    return;
  }
  long long sum = 0;
  long long cnt = 0;
  while (cnt <= n) {
    sum += C(n, cnt);
    sum %= mod;
    cnt += 2;
  }
  long long tmp = sum + 1 - (n % 2 == 0);
  for (int i = 0; i < k - 1; i++) {
    tmp = ((tmp % mod) * (sum % mod)) % mod;
  }
  cout << tmp << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  fac[0] = 0;
  fac[1] = 1;
  for (long long i = 2; i <= MAXN - 1; i++) {
    fac[i] = ((fac[i - 1] % mod) * (i % mod)) % mod;
  }
  int T;
  cin >> T;
  while (T-- > 0) {
    run_case();
  }
}

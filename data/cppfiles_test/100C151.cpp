#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
long long power(long long a, long long b) {
  long long res = 1;
  a = a % MOD;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
long long fermat_inv(long long y) { return power(y, MOD - 2); }
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
void solveQuestion() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long &x : arr) {
    cin >> x;
  }
  sort(arr.begin(), arr.end());
  long long ans = arr[0];
  for (long long i = 1; i < n; i++) {
    ans = max(ans, arr[i] - arr[i - 1]);
  }
  cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt = 1;
  cin >> tt;
  while (tt-- > 0) {
    solveQuestion();
  }
  return 0;
}

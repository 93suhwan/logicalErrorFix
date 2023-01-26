#include <bits/stdc++.h>
using namespace std;
const int si = 200001;
long long dp[si];
long long power(long long x, int y, int p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long n, int p) { return power(n, p - 2, p); }
long long nCrModPFermat(long long n, int r, int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return (dp[n] * modInverse(dp[r], p) % p * modInverse(dp[n - r], p) % p) % p;
}
void solve() {
  long long n;
  cin >> n;
  int arr[n];
  int flag = true;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  if ((arr[n - 1] == arr[n - 2]) > 1) {
    cout << 0;
    return;
  }
  if (arr[n - 1] == arr[n - 2]) {
    long long ans = dp[n];
    ans = ans % 998244353;
    cout << ans;
    return;
  }
  int ct = 0;
  for (int i = 0; i < n; i++) {
    if ((arr[n - 1] - arr[i]) > 1) {
      ct++;
    }
  }
  if (ct == 0) {
    long long ans = dp[n - 1] * (n - 1);
    ans = ans % 998244353;
    cout << ans;
    return;
  }
  long long ans = dp[n - 1] * (n - 1);
  ans = ans % 998244353;
  for (int r = 1; r <= ct; r++) {
    long long inv = nCrModPFermat(ct, r, 998244353);
    long long ann = (((inv * dp[r]) % 998244353) * dp[n - r - 1]) % 998244353;
    ans = ans - ann + 998244353;
    ans = ans % 998244353;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ;
  dp[0] = 1;
  for (int i = 1; i < si; i++) {
    dp[i] = dp[i - 1] * i;
    dp[i] = dp[i] % 998244353;
  }
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int si = 200001;
long long dp[si];
int modInverse(int a, int m) {
  int m0 = m;
  int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    int q = a / m;
    int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
void solve() {
  long long n;
  cin >> n;
  int arr[n];
  int brr[n];
  int flag = true;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    brr[i] = arr[i];
    if (i >= 1) {
      if (arr[i] != arr[i - 1]) {
        flag = false;
      }
    }
  }
  if (flag) {
    cout << dp[n];
    return;
  }
  sort(brr, brr + n);
  if ((brr[n - 1] - brr[n - 2]) > 1) {
    cout << 0;
    return;
  }
  int ct = 0;
  for (int i = 0; i < n; i++) {
    if ((brr[n - 1] - brr[i]) > 1) {
      ct++;
    }
  }
  if (ct == 0) {
    long long ans = dp[n - 1] * (n - 1);
    cout << ans;
    return;
  }
  long long ans = dp[n - 1] * (n - 1);
  for (int r = 1; r <= ct; r++) {
    long long inv = 0;
    int modr = modInverse(dp[r], 998244353);
    int modct = modInverse(dp[ct - r], 998244353);
    inv = dp[ct] * modr * (modct);
    long long ann = (inv * dp[r] * dp[n - r - 1]) % 998244353;
    ans = ans - ann;
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

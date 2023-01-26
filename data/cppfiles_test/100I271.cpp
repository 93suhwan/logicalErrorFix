#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const int N = 2e5 + 100;
int n;
int arr[N];
long long fac[N], inv[N];
long long quickmod(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i <= N; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  inv[1] = 1;
  for (int i = 2; i <= N; i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  sort(arr + 1, arr + 1 + n, greater<int>());
  int a = arr[1], b = arr[2];
  long long ans = fac[n];
  if (a - b > 1)
    ans = 0;
  else if (a == b + 1) {
    int cnt = 1;
    for (int i = 3; i <= n; i++)
      if (arr[i] == b)
        cnt++;
      else if (arr[i] < b)
        break;
    long long res = ans * inv[cnt + 1] % mod;
    ans = (ans - res + mod) % mod;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int Case;
  cin >> Case;
  while (Case--) solve();
  return 0;
}

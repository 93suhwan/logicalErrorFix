#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
using namespace std;
const long long N = 1e3 + 10, M = 20;
long long long long rang[N][N];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long long long n, k;
  cin >> n >> k;
  long long long long ans = 0;
  long long long long z = 1;
  while (z < n) {
    z *= k;
    ans++;
  }
  long long long long mx = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      long long long long a = i - 1;
      long long long long b = j - 1;
      long long long long cnt = 1;
      while (a % k == b % k) {
        a /= k;
        b /= k;
        cnt++;
      }
      rang[i][j] = cnt;
      mx = max(mx, cnt);
    }
  }
  cout << mx << endl;
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      cout << rang[i][j] << " ";
    }
  }
}

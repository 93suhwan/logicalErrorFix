#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
long long gcd(long long x, long long y) { return (!y) ? x : gcd(y, x % y); }
long long lcm(long long x, long long y) { return ((x / gcd(x, y) * y)); }
int arr[1001][1001];
int solve(int i, int j, int n, int m) {
  if (i == n) return j;
  int x = arr[i][j];
  arr[i][j] = 2;
  if (x == 1)
    return solve(i, j + 1, n, m);
  else if (x == 2)
    return solve(i + 1, j, n, m);
  else
    return solve(i, j - 1, n, m);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cin >> arr[i][j];
    }
    while (k--) {
      int x;
      cin >> x;
      --x;
      cout << solve(0, x, n, m) + 1 << " ";
    }
  }
  return 0;
}

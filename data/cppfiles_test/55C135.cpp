#include <bits/stdc++.h>
using namespace std;
long long int mpow(long long int x, long long int y) {
  long long int ans = 1;
  x = x % 1000000007;
  while (y) {
    if (y % 2 != 0) ans = (ans % 1000000007) * (x % 1000000007) % 1000000007;
    y /= 2;
    x = ((x % 1000000007) * (x % 1000000007)) % 1000000007;
  }
  return ans;
}
long long int x, s;
long long int solve(long long int n, long long int k) {
  if (k == 1) return 1;
  x = 0;
  s = 1;
  while (s <= k) {
    s = 2 * s + 1;
    x++;
  }
  s = (s - 1) / 2;
  k -= s;
  if (k == 1) return mpow(n, x);
  return (mpow(n, x) + solve(n, k - 1)) % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t, i, j;
  unsigned long long int ans = 6, p, n;
  cin >> n;
  for (i = 1; i < n; i++) {
    p = pow(2, i);
    ans = ((ans % 1000000007) * mpow(4, p)) % 1000000007;
  }
  cout << ans;
  return 0;
}

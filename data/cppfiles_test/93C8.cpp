#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long a, long long b) {
  if (b == 1) return a;
  if (b == 0) return 1;
  long long ans = power(a, b / 2);
  ans = (ans * ans);
  if (b & 1) ans = (ans * a);
  return ans;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << 0 << "\n";
    return;
  }
  if (k == 1) {
    cout << n - 1 << "\n";
    return;
  }
  long long x = 1;
  long long cnt = 0;
  while (x < k && n - x >= 0) {
    cnt++;
    x *= 2;
  }
  n -= x;
  cnt += (n + k - 1) / k;
  cout << cnt << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}

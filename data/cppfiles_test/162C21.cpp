#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long n, a[200005];
bool check(long long k) {
  long long b[n];
  for (int i = 0; i < n; i++) b[i] = a[i];
  for (int i = n - 1; i >= 2; i--) {
    if (b[i] > k) {
      long long d = min((b[i] - k) / 3, a[i] / 3);
      b[i - 2] += 2 * d;
      b[i - 1] += d;
      b[i] -= 3 * d;
    }
  }
  for (int i = 0; i < n; i++) {
    if (b[i] < k) return false;
  }
  return true;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long l = 1, r = 1000000005, ans;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      l = mid + 1;
      ans = mid;
    } else
      r = mid - 1;
  }
  cout << l - 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}

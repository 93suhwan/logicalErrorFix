#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int ans = 0;
  long long int x = 1;
  while (x < k && x < n) {
    ans++;
    x = x * 2;
  }
  if (x >= n) {
    cout << ans << endl;
    return;
  }
  n -= x;
  ans += n / k;
  if (n % k > 0) {
    ans++;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}

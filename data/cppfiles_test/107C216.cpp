#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, a, b;
  cin >> n >> a >> b;
  if (abs(a - b) > 1) {
    cout << -1 << "\n";
    return;
  }
  if (n % 2 == 0) {
    if (a >= (n / 2) || b >= (n / 2)) {
      cout << -1 << "\n";
      return;
    }
  } else {
    if (a > (n / 2) || b > (n / 2) || a == (n / 2) && b == (n / 2)) {
      cout << -1 << "\n";
      return;
    }
  }
  vector<long long int> ans;
  for (long long int i = 1; i <= n; i++) ans.push_back(i);
  {
    if (a == b) {
      for (long long int i = 1; i < n - 1 && a > 0; i += 2) {
        swap(ans[i], ans[i + 1]);
        a--;
      }
    } else if (a > b) {
      for (long long int i = n - (2 * a); i < n; i += 2) {
        swap(ans[i], ans[i + 1]);
      }
    } else {
      reverse(ans.begin(), ans.end());
      for (long long int i = n - (2 * b); i < n; i += 2) {
        swap(ans[i], ans[i + 1]);
      }
    }
  }
  for (long long int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  for (long long int test = 1; test <= t; test++) {
    solve();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool comp(long long int x, long long int y) { return x > y; }
const int N = 2e5 + 5;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n % 2 == 0) {
    cout << "YES\n";
    return;
  }
  int cur = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] > a[i]) {
      cur = 1;
      break;
    }
  }
  if (cur)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int32_t main() {
  cin.tie(0), cin.sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

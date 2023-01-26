#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  int odd_id = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    if (a[i] % 2 == 1) odd_id = i + 1;
  }
  bool all_okay = false;
  for (int k = 2; k * k <= sum; k++)
    if (sum % k == 0) {
      all_okay = true;
      break;
    }
  if (all_okay) {
    cout << n << endl;
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << endl;
  } else {
    cout << n - 1 << endl;
    for (int i = 1; i <= n; i++)
      if (i != odd_id) cout << i << " ";
    cout << endl;
  }
}
int main() {
  int t;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) solve();
  return 0;
}

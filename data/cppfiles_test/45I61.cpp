#include <bits/stdc++.h>
using namespace std;
using ll = long long;
long long M = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int b = 1;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != a[i + 1]) {
      b++;
    } else if (a[i] == a[i + 1] && a[i] == 0) {
      cout << -1 << endl;
      return;
    } else if (a[i] == a[i + 1] && a[i] == 1) {
      b += 5;
    }
  }
  cout << b << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

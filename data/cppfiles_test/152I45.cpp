#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int now = -a[1];
  int stage = 0;
  a[1] = -a[1];
  for (int i = 2; i <= n; i++) {
    if (-a[i] > a[i - 1]) {
      a[i] = -a[i];
      continue;
    }
    if (a[i] < a[i - 1]) {
      stage++;
      a[i] = -a[i];
    }
  }
  if (stage > 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}

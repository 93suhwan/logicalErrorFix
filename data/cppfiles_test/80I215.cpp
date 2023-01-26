#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<char> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = (n / 2); i < n; i++) {
    if (a[i] == '0') {
      cout << i - n / 2 + 1 << " " << i << " " << i - n / 2 + 1 << " " << i + 1
           << "\n";
      return;
    }
  }
  if (a[n / 2 - 1] == '0')
    cout << n / 2 << " " << n << " " << n / 2 + 1 << " " << n << "\n";
  else
    cout << n / 2 << " " << n - 1 << " " << n / 2 + 1 << " " << n << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}

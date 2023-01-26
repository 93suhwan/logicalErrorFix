#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string a;
  string b;
  int ans = 0;
  cin >> b >> a;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1' && b[i] == '0') {
      b[i] = '2';
      ans++;
    } else if (a[i] == '1' && i - 1 >= 0 && b[i - 1] == '1') {
      b[i - 1] = '2';
      ans++;
    } else if (a[i] == '1' && i + 1 < n && b[i + 1] == '1') {
      b[i + 1] = '2';
      ans++;
    }
  }
  cout << ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}

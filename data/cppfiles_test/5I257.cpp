#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string a;
  string b;
  int ans = 0;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    if (b[i] == '1' && i - 1 > 0 && b[i - 1] == '1' && a[i - 1] == '1') {
      ans++;
      a[i - 1] = '0';
    } else if (b[i] == '1' && i + 1 < n && b[i + 1] == '1' && a[i + 1] == '1') {
      ans++;
      a[i + 1] = '0';
    } else if (b[i] == '1' && a[i] == '0')
      ans++;
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

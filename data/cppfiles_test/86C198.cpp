#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      ans += 2;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      if (a[i] == '0') {
        if (i + 1 < n && a[i + 1] == '1' && b[i + 1] == '1') {
          ans += 2;
          i++;
        } else {
          ans += 1;
        }
      } else {
        if (i + 1 < n && a[i + 1] == '0' && b[i + 1] == '0') {
          ans += 2;
          i++;
        } else {
          ans += 0;
        }
      }
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

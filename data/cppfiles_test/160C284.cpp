#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int a[6], ans = 0, c1 = 1, c2 = 1;
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
  }
  while (a[2] != a[4] || a[3] != a[5]) {
    if (a[2] == a[4] || a[3] == a[5]) {
      break;
    }
    if (a[2] + c1 > a[0]) {
      c1 = -1;
    }
    if (a[3] + c2 > a[1]) {
      c2 = -1;
    }
    a[2] += c1;
    a[3] += c2;
    ans++;
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

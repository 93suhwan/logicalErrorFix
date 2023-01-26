#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int days[n];
    for (int i = 0; i < n; i++) {
      cin >> days[i];
    }
    long long ans = 1;
    long long flag = 1;
    for (int i = 0; i < n; i++) {
      if (i > 0 && days[i] == 0 && days[i - 1] == 0) {
        cout << -1 << '\n';
        flag = 0;
        break;
      }
      if (i > 0 && days[i] == 1 && days[i - 1] == 1) {
        ans += 5;
      } else if (days[i] == 1) {
        ans++;
      }
    }
    if (flag) cout << ans << '\n';
  }
}
int main() {
  solve();
  return 0;
}

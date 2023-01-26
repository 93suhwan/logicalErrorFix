#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll n;
  cin >> n;
  ll a[n + 2];
  bool flag = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    ll index = i + 1;
    if (a[i] % index != 0)
      cnt++;
    else {
      flag = 0;
      for (int j = 1; j <= cnt; j++) {
        if (a[i] % (index - j) != 0) {
          cnt++;
          flag = 1;
          break;
        }
      }
      if (!flag) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
  return;
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}

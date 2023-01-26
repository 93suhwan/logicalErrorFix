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
    if (a[i] % (i + 1) == 0) {
      flag = 1;
    }
  }
  if (flag)
    cout << "NO" << endl;
  else
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

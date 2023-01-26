#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 2e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < (int)(n); i++) cin >> a[i];
  sort((a).begin(), (a).end());
  for (int i = 0; i < (int)(n / 2); i++) {
    cout << a[i + 1] << ' ' << a[0] << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve(), cout << '\n';
}

#include <bits/stdc++.h>
using namespace std;
const int32_t mod = 1000000007;
const int32_t mod2 = 998244353;
const int32_t MAXN = 1000005;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 1; i <= n; i++) {
    bool ok = false;
    for (int j = 2; j <= i + 1 && j < 30; j++) {
      if (v[i] % j != 0) {
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  if (n % 3 == 0)
    cout << n / 3 << ' ' << n / 3 << '\n';
  else if (n % 3 == 1)
    cout << (n / 3) + 1 << ' ' << n / 3 << '\n';
  else
    cout << (n / 3) << ' ' << (n / 3) + 1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}

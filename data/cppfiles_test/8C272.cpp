#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 5e5 + 3;
const int INF = 2e9 + 7;
const double EPS = 1e-12;
void solve() {
  int sum;
  cin >> sum;
  int x = sum / 3, r = sum % 3;
  if (r == 0)
    cout << x << ' ' << x << endl;
  else if (r == 1)
    cout << sum - 2 * x << ' ' << x << endl;
  else
    cout << x << ' ' << (sum - x) / 2 << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}

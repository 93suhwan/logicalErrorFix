#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int N = 1e6 + 10;
const long double eps = 1e-6;
const int mod = 1e9 + 7;
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  cout << ((a + b * 2 + c * 3) % 2) << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

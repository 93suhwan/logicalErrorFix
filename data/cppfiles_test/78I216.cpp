#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
void solve() {
  int a, b;
  cin >> a >> b;
  if (abs(a - b) == 0) {
    cout << 0 << "\n";
    return;
  } else if (b - a == 1) {
    cout << 1 << "\n";
    return;
  }
  int k = (b / 2) + 1;
  if (k >= a) {
    cout << b % k << "\n";
    return;
  }
  int z1 = b;
  int ans{};
  while (2 * a <= b) {
    ans = max(2 * a % ((a) + 1), ans);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}

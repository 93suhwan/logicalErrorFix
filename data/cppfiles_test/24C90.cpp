#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;
void solve() {
  int n;
  cin >> n;
  if (n < 9) {
    cout << 0 << '\n';
  } else if (n % 10 == 9) {
    cout << (n / 10) + 1 << '\n';
  } else {
    cout << (n / 10) << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
}

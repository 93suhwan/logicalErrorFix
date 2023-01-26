#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 5e5 + 3;
const int INF = 2e9 + 7;
const double EPS = 1e-12;
void solve() {
  int n;
  cin >> n;
  int c1, c2, ans = INF;
  for (int x = n / 3 - 2; x <= n / 3 + 2; x++) {
    for (int y = n / 3 - 2; y <= n / 3 + 2; y++) {
      if (x + y * 2 == n && abs(x - y) < ans) {
        ans = abs(x - y);
        c1 = x, c2 = y;
      }
    }
  }
  cout << c1 << ' ' << c2 << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}

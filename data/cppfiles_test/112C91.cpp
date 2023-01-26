#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;
constexpr int KINF = 0x3f3f3f3f;
constexpr int INF = 0x7f7f7f7f;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int l = max(0, (max({a, b, c}) - 1) - (a + b + c) + max({a, b, c}));
    int r = max(a - 1, 0) + max(b - 1, 0) + max(c - 1, 0);
    cout << (m >= l && m <= r ? "YES\n" : "NO\n");
  }
  return 0;
}

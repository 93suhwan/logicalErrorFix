#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, a[maxn];
bool Ok(int val, int c1, int c2, int c3) {
  for (int x1 = 0; x1 <= c1; ++x1) {
    for (int x2 = 0; x2 <= c2; ++x2) {
      int res = x1 + x2 * 2;
      if (res == val) return 1;
      if (res < val && abs(res - val) % 3 == 0 && abs(res - val) / 3 <= c3)
        return 1;
    }
  }
  return 0;
}
bool Check(int c1, int c2, int c3) {
  for (int i = 1; i <= n; ++i) {
    if (!Ok(a[i], c1, c2, c3)) return 0;
  }
  return 1;
}
void Solve(int Test) {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int mx = *max_element(a + 1, a + n + 1);
  int ans = 2e9;
  for (int c1 = 0; c1 <= 3; ++c1) {
    for (int c2 = 0; c2 <= 3; ++c2) {
      int c3 = (mx - c1 - 2 * c2 + 2) / 3;
      if (Check(c1, c2, c3)) ans = min(ans, c1 + c2 + c3);
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if (fopen("CF"
            ".inp",
            "r")) {
    freopen(
        "CF"
        ".inp",
        "r", stdin);
    freopen(
        "CF"
        ".out",
        "w", stdout);
  }
  int test = 1;
  cin >> test;
  for (int i = 1; i <= test; ++i) {
    Solve(i);
  }
}

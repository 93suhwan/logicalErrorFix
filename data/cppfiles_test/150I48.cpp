#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, a[maxn];
bool Ok(int val, int c1, int c2, int c3) {
  int x = c1 + c2 * 2 + c3 * 3, bonus = 0;
  while (x - 3 > val) x -= 3, bonus++;
  if (x == val) return 1;
  if (x == val + 2) {
    if (c1 >= 2 || c2 >= 1) return 1;
    return 0;
  }
  if (c1 >= 1) return 1;
  if (c2 >= 2 && bonus) return 1;
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
  int test = 1;
  cin >> test;
  for (int i = 1; i <= test; ++i) {
    Solve(i);
  }
}

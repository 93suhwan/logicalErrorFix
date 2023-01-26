#include <bits/stdc++.h>
using namespace std;
int zeros(int x, int b) {
  int r = 0;
  if (((x >> b) ^ 1) & 1) {
    r += (x & ((1 << b) - 1)) + 1;
  } else {
    r += (1 << b);
  }
  x >>= b + 1;
  return r + x * (1 << b);
}
void solve() {
  int a, b;
  cin >> a >> b;
  int ans = 1e9;
  for (int i = 0; i < 20; ++i) {
    ans = min(ans, zeros(b, i) - zeros(a, i) + (((a >> i) & 1) ^ 1));
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

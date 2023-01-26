#include <bits/stdc++.h>
using namespace std;
void solve() {
  int N, M, A, B, C, D;
  cin >> N >> M >> A >> B >> C >> D;
  int dR = 1, dC = 1;
  int ans = 0;
  while (A != C && B != D) {
    A += dR;
    B += dC;
    if (A > N) A -= 2, dR = -1;
    if (A <= 0) A += 2, dR = 1;
    if (B > M) B -= 2, dC = -1;
    if (B <= 0) B += 2, dC = 1;
    ans++;
  }
  cout << ans << '\n';
}
int main() {
  int t = 1;
  for (cin >> t; t; t--) solve();
  return 0;
}

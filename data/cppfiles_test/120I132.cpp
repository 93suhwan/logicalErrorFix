#include <bits/stdc++.h>
using namespace std;
const int N = (int)3e5 + 7, MOD = (int)1e9 + 7;
int l, r;
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> l >> r;
    int cur = 0, mx = 0;
    for (int i = 1; i <= 20; i++) {
      int L = (1 << cur), R = (1 << (cur + 1)) - 1;
      mx = max(mx, min(r, R) - max(l, L) + 1);
      cur++;
    }
    cout << r - l + 1 - mx << "\n";
  }
  exit(0);
}

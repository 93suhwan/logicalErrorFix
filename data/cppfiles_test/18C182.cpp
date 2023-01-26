#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    vector<int> vec(n);
    vector<bool> vis(n, false);
    for (auto& v : vec) cin >> v;
    int maxAmt = -INF;
    bool nda = false;
    for (int i = 0; i < n; i++) {
      if (vis[i]) continue;
      int amt, result = 1;
      for (amt = 0; (amt == 0 || i != (i + amt * d) % n) && result; amt++) {
        result &= vec[(i + amt * d) % n];
        vis[(i + amt * d) % n] = true;
      }
      amt--;
      maxAmt = max(maxAmt, amt);
      if (result == 1) {
        nda = true;
        break;
      }
    }
    if (nda)
      cout << -1 << '\n';
    else
      cout << maxAmt << '\n';
  }
  exit(0);
}

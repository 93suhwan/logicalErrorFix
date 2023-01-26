#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
int n, m, k, t, S, B, s, b;
void solve() {
  cin >> n >> m >> k;
  B = (n + m - 1) / m, S = n / m;
  b = n % m, s = m - b;
  int tmp = 0;
  for (int t = 1; t <= k; t++) {
    vector<int> vis(n, 0);
    for (int i = 0; i < b; i++) {
      cout << B << " ";
      for (int j = 1; j <= B; j++, tmp++) {
        vis[tmp % n] = 1;
        cout << tmp % n + 1 << " \n"[j == B];
      }
    }
    int cnt = 0;
    cout << S << " ";
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        cnt++;
        cout << i + 1 << " \n"[cnt % S == 0];
        if (cnt % S == 0 && cnt != s * S) cout << S << " ";
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}

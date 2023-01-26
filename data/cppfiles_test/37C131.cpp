#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1, SQR = 1e3, INF = 1e9 + 10, MOD = 1e9 + 7;
const long long LINF = 1e18 + 10;
char used[N];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) used[i] = 0;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    used[b] = 1;
  }
  int x = -1;
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      x = i;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != x) cout << x << " " << i << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

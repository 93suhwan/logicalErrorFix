#include <bits/stdc++.h>
using namespace std;
const int N = 300 + 1;
int n, m;
int sight[N];
void input() {
  cin >> n >> m;
  for (int i = 1; i <= n * m; i++) cin >> sight[i];
}
const int INF = 1e8;
int val[N * N + 1], seat[N];
bool is_free[N];
void solve() {
  for (int i = 1; i <= n * m; i++) val[i] = sight[i];
  sort(val + 1, val + n * m + 1);
  val[n * m + 1] = INF;
  for (int i = 1; i <= n * m; i++) {
    int j = upper_bound(val + 1, val + n * m + 1, sight[i]) - val - 1;
    seat[i] = j;
    val[j] = val[j + 1];
  }
  fill(is_free + 1, is_free + m + 1, true);
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= seat[i]; j++)
      if (not is_free[j]) ans++;
    is_free[seat[i]] = false;
  }
  cout << ans << endl;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    input();
    solve();
  }
  return 0;
}

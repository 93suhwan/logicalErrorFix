#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
const int ALPHA = 40;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int LOG = 22;
const long long LONG_INF = 1e18;
int n, m, q, u, v, death_sum, kind;
int better_connected[MAXN];
bool to_die[MAXN];
void Solve() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    if (!to_die[min(--u, --v)]) {
      to_die[min(u, v)] = 1;
      death_sum++;
    }
    better_connected[min(u, v)]++;
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> kind;
    if (kind == 3) {
      cout << n - death_sum << '\n';
    } else if (kind == 1) {
      cin >> u >> v;
      if (!to_die[min(--u, --v)]) {
        to_die[min(u, v)] = 1;
        death_sum++;
      }
      better_connected[min(u, v)]++;
    } else {
      cin >> u >> v;
      better_connected[min(--u, --v)]--;
      if (!better_connected[min(u, v)]) {
        to_die[min(u, v)] = 0;
        death_sum--;
      }
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Solve();
}

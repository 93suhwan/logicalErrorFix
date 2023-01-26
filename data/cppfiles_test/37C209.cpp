#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  int a, b, c;
  map<int, int> mp;
  vector<int> graph[n + 5];
  for (int i = 1; i <= m; i++) {
    cin >> a >> b >> c;
    mp[b] = 1;
  }
  int node = -1;
  for (int i = 1; i <= n; i++) {
    if (!mp[i]) {
      node = i;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i == node) continue;
    cout << i << " " << node << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
  return 0;
}

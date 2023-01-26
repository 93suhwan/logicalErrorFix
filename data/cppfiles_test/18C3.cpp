#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
clock_t start = clock();
const int MOD = 998244353;
int v[(int)1e6 + 5], bit[(int)1e6 + 5];
void add(int pos, int x, int n) {
  for (; pos <= n; pos += pos & (-pos)) bit[pos] += x;
}
int qry(int pos) {
  int ans = 0;
  for (; pos > 0; pos -= pos & (-pos)) ans += bit[pos];
  return ans;
}
void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> vis(n, (int)1e9);
  queue<int> bfs;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 0) {
      vis[i] = 0;
      bfs.push(i);
    }
  }
  while (!bfs.empty()) {
    auto x = bfs.front();
    bfs.pop();
    int y = (x + d) % n;
    if (vis[y] > vis[x] + 1) {
      vis[y] = vis[x] + 1;
      bfs.push(y);
    }
  }
  int ans = -1;
  for (int i = 0; i < n; ++i) ans = max(ans, vis[i]);
  if (ans >= (int)1e9) ans = -1;
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << fixed << setprecision(10);
  cerr << "Time taken = " << (clock() - start) / ((double)CLOCKS_PER_SEC)
       << " s\n";
  return 0;
}

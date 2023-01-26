#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int d[200005];
struct peo {
  int id, d;
  bool operator<(const peo& p) const { return d > p.d; }
};
void solve() {
  cin >> n >> m >> k;
  priority_queue<peo> que;
  for (int i = 1; i <= n; i++) {
    que.push({i, 0});
    d[i] = 0;
  }
  for (int t = 0; t < k; t++) {
    for (int i = 0; i < n % m; i++) {
      cout << (n + m - 1) / m << ' ';
      for (int j = 0; j < (n + m - 1) / m; j++) {
        cout << que.top().id << ' ';
        d[que.top().id]++;
        que.pop();
      }
      cout << '\n';
    }
    for (int i = 0; i < m - n % m; i++) {
      cout << n / m << ' ';
      for (int j = 0; j < n / m; j++) {
        cout << que.top().id << ' ';
        que.pop();
      }
      cout << '\n';
    }
    assert(que.size() == 0);
    for (int i = 1; i <= n; i++) {
      que.push({i, d[i]});
    }
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}

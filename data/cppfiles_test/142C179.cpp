#include <bits/stdc++.h>
using namespace std;
const int SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
void test_case() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> p(n, vector<int>(m));
  for (auto &r : p)
    for (auto &x : r) cin >> x;
  int mx = 0x3f3f3f3f;
  for (int j = 0; j < m; j++) {
    int best = 0;
    for (int i = 0; i < n; i++) best = max(best, p[i][j]);
    mx = min(best, mx);
  }
  int m1 = 0;
  for (int i = 0; i < n; i++) {
    sort(p[i].rbegin(), p[i].rend());
    m1 = max(p[i][1], m1);
  }
  cout << min(mx, m1) << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    test_case();
  }
  return 0;
}

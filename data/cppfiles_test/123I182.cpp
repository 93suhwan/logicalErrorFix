#include <bits/stdc++.h>
using namespace std;
bool isrange(int second, int first, int n, int m) {
  if (0 <= second && second < n && 0 <= first && first < m) return true;
  return false;
}
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1},
    ddy[8] = {1, 0, -1, 0, 1, 1, -1, -1}, ddx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int MAX = 2e5 + 100;
vector<int> v[MAX];
vector<int> res[MAX];
int leaf;
int dfs(int first, int lx) {
  vector<int> tx;
  for (int e = 0; e < (int)v[first].size(); e++) {
    int nx = v[first][e];
    if (nx != lx) {
      int k = dfs(nx, first);
      tx.push_back(k);
      if ((int)res[first].size() < (int)res[nx].size())
        swap(res[first], res[nx]);
      for (int e = 0; e < (int)res[nx].size(); e++)
        res[first].push_back(res[nx][e]);
      res[nx].clear();
    }
  }
  sort(tx.begin(), tx.end());
  for (int e = 0; e < (int)tx.size() - 1; e++) res[first].push_back(tx[e]);
  if ((int)tx.size() == 0) {
    leaf++;
    return 1;
  }
  return tx[(int)tx.size() - 1] + 1;
}
void solve(int tc) {
  int n, k;
  cin >> n >> k;
  for (int e = 0; e < n - 1; e++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int t = dfs(1, -1);
  if (k >= leaf) {
    long long int ans = -1e18;
    for (int p = leaf; p <= k; p++) {
      ans = max(ans, 1ll * (n - p) * p);
    }
    cout << ans << "\n";
    return;
  }
  res[1].push_back(t);
  sort(res[1].begin(), res[1].end());
  int b = n;
  for (int e = (int)res[1].size() - 1; e >= max(0, (int)res[1].size() - k); e--)
    b -= res[1][e];
  cout << 1ll * (n - (b + k)) * (k - b) << "\n";
}
int main(void) {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  for (int test_number = 1; test_number <= tc; test_number++) {
    solve(test_number);
  }
  return 0;
}

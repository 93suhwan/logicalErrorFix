#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int N, M;
int a[maxn][maxn];
int f[maxn][maxn];
vector<int> res;
int dfs(int i, int j) {
  int sum = 0;
  f[i][j] = 1;
  if (!(a[i][j] & 1) && !f[i][j - 1]) {
    sum += dfs(i, j - 1);
  }
  if (!(a[i][j] & 2) && !f[i + 1][j]) {
    sum += dfs(i + 1, j);
  }
  if (!(a[i][j] & 4) && !f[i][j + 1]) {
    sum += dfs(i, j + 1);
  }
  if (!(a[i][j] & 8) && !f[i - 1][j]) {
    sum += dfs(i - 1, j);
  }
  return sum + 1;
}
void dfs_s() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int x;
      if (!f[i][j]) {
        x = dfs(i, j);
        res.push_back(x);
      }
    }
  }
}
bool cmp(int a, int b) { return a > b; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }
  dfs_s();
  sort(res.begin(), res.end(), cmp);
  for (auto &x : res) {
    cout << x << " ";
  }
  cout << endl;
}

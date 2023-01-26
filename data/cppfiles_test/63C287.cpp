#include <bits/stdc++.h>
using namespace std;
const int mod = (int)(1e9 + 7);
const int N = 1005;
int par[N], sz[N];
int par1[N], sz1[N];
int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}
void Union(int x, int y) {
  int X = find(x);
  int Y = find(y);
  if (X == Y) return;
  sz[X] += sz[Y];
  par[Y] = X;
}
int find1(int x) {
  if (par1[x] == x) return x;
  return par1[x] = find1(par1[x]);
}
void Union1(int x, int y) {
  int X = find1(x);
  int Y = find1(y);
  if (X == Y) return;
  sz1[X] += sz1[Y];
  par1[Y] = X;
}
void solve(int test) {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  for (int i = 0; i <= N; i++) {
    par[i] = i;
    sz[i] = 1;
    par1[i] = i;
    sz1[i] = 1;
  }
  int a[n + 1][n + 1], b[n + 1][n + 1];
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (int i = 1; i <= m1; i++) {
    int u, v;
    cin >> u >> v;
    a[u][v] = 1;
    a[v][u] = 1;
    Union(u, v);
  }
  for (int i = 1; i <= m2; i++) {
    int u, v;
    cin >> u >> v;
    b[u][v] = 1;
    b[v][u] = 1;
    Union1(u, v);
  }
  int ans = 0;
  vector<pair<int, int> > res;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i][j] == 0 and b[i][j] == 0) {
        int t1 = find(i);
        int t2 = find(j);
        int t3 = find1(i);
        int t4 = find1(j);
        int check1 = 1, check2 = 1;
        if (t1 == t2) check1 = 0;
        if (t3 == t4) check2 = 0;
        if (check1 == 0 or check2 == 0) continue;
        ans++;
        res.push_back({i, j});
        if (a[i][j] == 0) {
          Union(i, j);
          a[i][j] = 1;
          a[j][i] = 1;
        }
        if (b[i][j] == 0) {
          Union1(i, j);
          b[i][j] = 1;
          b[j][i] = 1;
        }
      }
    }
  }
  cout << ans << endl;
  for (auto e : res) {
    cout << e.first << " " << e.second << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int test_cases = 1;
  srand(time(NULL));
  for (int i = 1; i <= test_cases; i++) {
    solve(i);
  }
  return 0;
}

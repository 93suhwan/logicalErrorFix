#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int dx1[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy1[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
const double eps = 1e-9;
const int inf = 2000000000;
const long long int infLL = 9000000000000000000;
const long long int MOD = 1e+7;
const double PI = 3.141592653589793238462643383279;
const int N = 1e3 + 10;
vector<pair<int, int> > v;
int ans[N], c(0);
bool vis[N][N];
void dfs(int l, int r) {
  if (l == r)
    v.push_back(make_pair(l, r)), ans[c++] = l;
  else {
    if (vis[l + 1][r])
      v.push_back(make_pair(l, r)), ans[c++] = l, dfs(l + 1, r);
    else if (vis[l][r - 1])
      v.push_back(make_pair(l, r)), ans[c++] = r, dfs(l, r - 1);
    else {
      for (long long int i = l + 1; i < r; i++) {
        if (vis[l][i - 1] && vis[i + 1][r]) {
          v.push_back(make_pair(l, r)), ans[c++] = i;
          dfs(l, i - 1), dfs(i + 1, r);
          break;
        }
      }
    }
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  std ::cin >> t;
  while (t--) {
    int n, x, y;
    memset(vis, 0, sizeof(vis));
    v.clear();
    c = 0;
    cin >> n;
    for (long long int i = 0; i < n; i++) cin >> x >> y, vis[x][y] = 1;
    dfs(1, n);
    for (long long int i = 0; i < c; i++)
      cout << v[i].first << ' ' << v[i].second << ' ' << ans[i] << endl;
    std ::cout << endl;
  }
  return 0;
}

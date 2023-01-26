#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 200010;
int c[2][N][2];
int lowbit(int x) { return x & (-x); }
void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
void add(int id, int x, int y) {
  x++;
  for (int i = x; i < N; i += lowbit(i)) {
    add(c[id][i][0], y);
    add(c[id][i][1], 1);
  }
}
pair<int, int> query(int id, int x) {
  x++;
  int sum = 0, tot = 0;
  for (int i = x; i > 0; i -= lowbit(i)) {
    add(sum, c[id][i][0]);
    add(tot, c[id][i][1]);
  }
  return make_pair(sum, tot);
}
void unset(int id, int x) {
  x++;
  for (int i = x; i < N; i += lowbit(i)) c[id][i][0] = c[id][i][1] = 0;
}
int max_dis;
int a[N];
vector<int> v[N], w[N];
pair<int, int> pt[N];
bool visit[N];
int sz[N], msz[N], cnt;
void dfs(int u, int fa) {
  sz[u] = 1;
  msz[u] = 0;
  for (int i = 0; i < v[u].size(); i++) {
    int first = v[u][i];
    if (first != fa && !visit[first]) {
      dfs(first, u);
      sz[u] += sz[first];
      msz[u] = max(msz[u], sz[first]);
    }
  }
  pt[cnt++] = make_pair(u, msz[u]);
}
int get_center(int u) {
  cnt = 0;
  dfs(u, 0);
  int ans = 0, mi = 0x7fffffff;
  int sum = sz[u];
  for (int i = 0; i < cnt; i++) {
    pt[i].second = max(pt[i].second, sum - pt[i].second);
    if (pt[i].second < mi) {
      mi = pt[i].second;
      ans = pt[i].first;
    }
  }
  return ans;
}
int ans;
int root_val;
struct point {
  int cost, col;
  long long sum;
  point() {}
  point(int cost, int col, long long sum) : cost(cost), col(col), sum(sum) {}
} records[N];
int cc;
void dfs(int u, int fa, int cost, int col, long long sum, int old_col) {
  if (cost > max_dis) return;
  add(ans, sum % mod);
  pair<int, int> t = query(old_col, max_dis - cost);
  add(ans, t.first);
  add(ans, 1LL * (sum - root_val) % mod * t.second % mod);
  if (cost < max_dis) {
    t = query(old_col ^ 1, max_dis - cost - 1);
    add(ans, t.first);
    add(ans, 1LL * (sum - root_val) % mod * t.second % mod);
  }
  records[++cc] = point(cost, old_col, sum);
  for (int i = 0; i < v[u].size(); i++) {
    int first = v[u][i];
    if (first == fa || visit[first]) continue;
    dfs(first, u, cost + (col != w[u][i]), w[u][i], sum + a[first], old_col);
  }
}
void cal(int u) {
  root_val = a[u];
  cc = 0;
  for (int i = 0; i < v[u].size(); i++) {
    int first = v[u][i];
    if (visit[first]) continue;
    int pre = cc;
    dfs(first, u, 0, w[u][i], a[u] + a[first], w[u][i]);
    for (int j = pre + 1; j <= cc; j++) {
      add(records[j].col, records[j].cost, records[j].sum % mod);
    }
  }
  for (int j = 1; j <= cc; j++) unset(records[j].col, records[j].cost);
  visit[u] = true;
  add(ans, a[u]);
}
void solve(int u, int fa) {
  u = get_center(u);
  cal(u);
  for (int i = 0; i < v[u].size(); i++) {
    int first = v[u][i];
    if (first != fa && !visit[first]) solve(first, u);
  }
}
int main() {
  int n;
  scanf("%d%d", &n, &max_dis);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) {
    int first, second, z;
    scanf("%d%d%d", &first, &second, &z);
    v[first].push_back(second);
    w[first].push_back(z);
    v[second].push_back(first);
    w[second].push_back(z);
  }
  solve(1, 0);
  cout << ans << endl;
  return 0;
}

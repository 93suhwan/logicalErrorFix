#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k, bin[N], dep[N], mx[N];
vector<int> v[N];
bool leaf[N];
inline int Find(int x) { return bin[x] == x ? x : bin[x] = Find(bin[x]); }
void join(int x, int y) { bin[Find(y)] = Find(x); }
void dfs1(int now, int fa) {
  mx[now] = dep[now] = dep[fa] + 1;
  int son = -1;
  for (int i = 0; i < v[now].size(); i++) {
    int to = v[now][i];
    if (to == fa) continue;
    dfs1(to, now);
    mx[now] = max(dep[now], mx[to]);
    if (son == -1 || mx[to] > mx[son]) son = to;
  }
  if (son != -1)
    join(now, son);
  else
    leaf[now] = true;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++) bin[i] = i, leaf[i] = false;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs1(0, 0);
  vector<int> e;
  e.clear();
  for (int i = 0; i < n; i++)
    if (leaf[i]) e.push_back(dep[i] - dep[Find(i)] + 1);
  sort(e.begin(), e.end());
  int m = 0;
  long long ans = -1e17;
  reverse(e.begin(), e.end());
  for (int r = 0; r <= k; r++) {
    if (r <= e.size() && r) m += e[r - 1];
    int p = min(n - m, n / 2);
    ans = max(ans, 1ll * r * (n - r) - 1ll * p * (n - p));
  }
  cout << ans << "\n";
  return 0;
}

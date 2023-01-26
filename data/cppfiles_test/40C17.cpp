#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const long long INF = 1e9 + 10;
long long MOD = 1e9 + 7;
long double EPS = 1e-12;
void fastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int n, m, q;
vector<vector<int> > v;
bool was[MAXN];
set<pair<int, int> > st;
vector<int> dfs(int u, int endd) {
  was[u] = 1;
  if (u == endd) return {u + 1};
  for (auto to : v[u]) {
    if (was[to]) continue;
    if (st.find({min(u, to), max(u, to)}) == st.end()) continue;
    vector<int> res = dfs(to, endd);
    if (res.size() != 0) {
      st.erase({min(u, to), max(u, to)});
      res.push_back(u + 1);
      return res;
    }
  }
  for (auto to : v[u]) {
    if (was[to]) continue;
    if (st.find({min(u, to), max(u, to)}) != st.end()) continue;
    vector<int> res = dfs(to, endd);
    if (res.size() != 0) {
      st.insert({min(u, to), max(u, to)});
      res.push_back(u + 1);
      return res;
    }
  }
  return {};
}
int vp(int u) {
  was[u] = 1;
  int sum = 0, cnt = 0;
  for (auto to : v[u]) {
    if (st.find({min(u, to), max(u, to)}) == st.end()) continue;
    cnt++;
    if (was[to] == 0) sum += vp(to);
  }
  return sum + (int)(cnt == 1);
}
int main() {
  fastIO();
  cin >> n >> m;
  v.resize(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[x - 1].push_back(y - 1);
    v[y - 1].push_back(x - 1);
  }
  cin >> q;
  vector<vector<int> > ans;
  vector<int> cnt_from(n);
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    cnt_from[a]++;
    cnt_from[b]++;
    fill(was, was + n, 0);
    vector<int> res = dfs(a, b);
    reverse(res.begin(), res.end());
    ans.push_back(res);
  }
  if (st.empty()) {
    cout << "YES\n";
    for (auto it : ans) {
      cout << it.size() << '\n';
      for (auto ver : it) cout << ver << ' ';
      cout << '\n';
    }
  } else {
    cout << "NO\n";
    int bad_cnt = 0;
    for (int i = 0; i < n; i++) {
      if (cnt_from[i] % 2 != 0) bad_cnt++;
    }
    cout << bad_cnt / 2;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << '(' << p.first << ',' << ' ' << p.second << ')';
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << '[';
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ',';
    cout << v[i];
  }
  return cout << ']' << endl;
}
const long long mod = 1000000007;
bool compare1(vector<int> &a, vector<int> &b) {
  if (a[0] == b[0]) {
    return a[1] < b[1];
  }
  return a[0] < b[0];
}
bool compare2(vector<int> &a, vector<int> &b) {
  if (a[1] == b[1]) {
    return a[0] < b[0];
  }
  return a[1] < b[1];
}
void dfs(int cur, int par, vector<vector<int>> &tree, vector<int> &vis, int &c,
         vector<int> &val) {
  vis[cur] = 1;
  c = min(c, val[cur]);
  for (auto it : tree[cur]) {
    if (!vis[it]) {
      dfs(it, cur, tree, vis, c, val);
    }
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> val(n, vector<int>(4));
  vector<vector<int>> tree(n);
  vector<int> vis(n);
  vector<int> cost(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> val[i][j];
    }
    val[i][3] = i;
    cost[i] = val[i][2];
  }
  sort(val.begin(), val.end(), compare1);
  for (int i = 1; i < n; i++) {
    if (val[i][0] == val[i - 1][0] && abs(val[i][1] - val[i - 1][1]) <= k) {
      tree[val[i][3]].push_back(val[i - 1][3]);
      tree[val[i - 1][3]].push_back(val[i][3]);
    }
  }
  sort(val.begin(), val.end(), compare2);
  for (int i = 1; i < n; i++) {
    if (val[i][1] == val[i - 1][1] && abs(val[i][0] - val[i - 1][0]) <= k) {
      tree[val[i][3]].push_back(val[i - 1][3]);
      tree[val[i - 1][3]].push_back(val[i][3]);
    }
  }
  deque<int> st;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      int c = INT_MAX;
      dfs(i, i, tree, vis, c, cost);
      st.push_back(c);
    }
  }
  sort(st.begin(), st.end());
  int t = ((int)st.size()) - 1;
  for (int i = 0; i < ((int)st.size()); i++) {
    t = min(t, max(st[i], ((int)st.size()) - i - 2));
  }
  cout << t << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}

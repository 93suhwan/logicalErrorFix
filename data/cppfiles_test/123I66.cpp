#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
const int MAXN = 2e5 + 10;
const int INF = 1e9;
int n, k;
vector<int> g[MAXN], res;
int dfs(int v, int p = -1) {
  vector<int> tmp;
  for (auto u : g[v]) {
    if (u != p) {
      tmp.push_back(dfs(u, v));
    }
  }
  if (tmp.empty()) return 1;
  sort(tmp.begin(), tmp.end());
  for (int i = 0; i < tmp.size() - 1; i++) {
    res.push_back(tmp[i]);
  }
  return tmp.back() + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  res.push_back(dfs(1));
  sort(res.begin(), res.end(), greater<int>());
  int bad = n;
  if (res.size() < k) {
    int x = min(k, n / 2);
    cout << 1LL * x * (n - x) << '\n';
    return 0;
  }
  for (int i = 0; i < k; i++) {
    bad -= res[i];
  }
  cout << 1LL * (n - bad - k) * (k - bad) << '\n';
  return 0;
}

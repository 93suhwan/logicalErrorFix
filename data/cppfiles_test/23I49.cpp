#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <class T, class... U>
void debug(T a, U... b) {
  cout << a << " ";
  debug(b...);
}
template <class T>
void pary(T l, T r) {
  while (l != r) {
    cout << *l << " ";
    l++;
  }
  cout << endl;
}
const long long inf = (1LL << 60);
vector<pair<int, int> > adj[4005];
int a[4005], par[4005];
int m;
vector<long long> dfs(int n, int pa) {
  vector<long long> ret(2, 0);
  for (auto v : adj[n]) {
    if (v.first != pa) {
      vector<long long> tmp = dfs(v.first, n);
      int siz = ret.size() + tmp.size() - 1;
      vector<long long> cur(siz, -inf);
      for (int i = 0; i < siz; i++) {
        long long val = -inf;
        for (int j = max(i - (int)ret.size() + 1, 0);
             j <= min(i, (int)tmp.size() - 1); j++) {
          val = max(val, tmp[j] + v.second * j * (m - j) + ret[i - j]);
        }
        cur[i] = val;
      }
      ret = cur;
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  stack<int> stk;
  for (int i = 1; i <= n; i++) {
    int prv = 0;
    while (stk.size() && a[i] <= a[stk.top()]) {
      prv = stk.top();
      stk.pop();
    }
    if (prv) par[prv] = i;
    if (stk.size()) par[i] = stk.top();
    stk.push(i);
  }
  for (int i = 1; i <= n; i++) {
    if (par[i]) {
      adj[i].push_back({par[i], a[i] - a[par[i]]});
      adj[par[i]].push_back({i, a[i] - a[par[i]]});
    }
  }
  vector<long long> ans = dfs(1, 0);
  cout << ans[m] << "\n";
}

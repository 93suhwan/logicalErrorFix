#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
struct o {
  int a, b, p;
};
void MAIN() {
  int n;
  cin >> n;
  set<pair<int, int>> v1, v2;
  int x;
  pair<int, int> p[n + 1];
  for (int i = 1; i <= n; i++) cin >> x, v1.insert({x, i}), p[i].first = x;
  for (int i = 1; i <= n; i++) cin >> x, v2.insert({x, i}), p[i].second = x;
  vector<int> ans(n + 1);
  queue<o> q;
  q.push(
      {v1.rbegin()->first, p[v1.rbegin()->second].second, v1.rbegin()->second});
  q.push(
      {p[v2.rbegin()->second].first, v2.rbegin()->first, v2.rbegin()->second});
  ans[v1.rbegin()->second] = 1;
  ans[v2.rbegin()->second] = 1;
  v1.erase(*v1.rbegin());
  v2.erase(*v2.rbegin());
  while (!q.empty()) {
    o c = q.front();
    q.pop();
    while (!v1.empty() && v1.rbegin()->first >= c.a) {
      int u = v1.rbegin()->second;
      if (!ans[u]) {
        ans[u] = 1;
        q.push({p[u].first, p[u].second, u});
      }
      v1.erase(*v1.rbegin());
    }
    while (!v2.empty() && v2.rbegin()->first >= c.b) {
      int u = v2.rbegin()->second;
      if (!ans[u]) {
        ans[u] = 1;
        q.push({p[u].first, p[u].second, u});
      }
      v2.erase(*v2.rbegin());
    }
  }
  for (int i = 1; i <= n; i++) cout << ans[i];
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int t;
  cin >> t;
  while (t--) MAIN();
}

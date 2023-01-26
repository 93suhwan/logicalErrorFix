#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 3e5 + 5;
int n, a[N], b[N], c[N], t[N];
pair<int, int> par[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  queue<int> Q;
  set<int> S;
  for (int i = 1; i < n; i++) S.insert(i), t[i] = 1e9;
  Q.push(n);
  t[n] = 1;
  int inx = -1;
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    int y = x - a[x];
    if (a[x] >= x) {
      inx = x;
    }
    while (!S.empty()) {
      auto it = S.lower_bound(y);
      if (it == S.end() || *it > x) break;
      if (t[*it + b[*it]] > t[x] + 1) {
        t[*it + b[*it]] = min(t[*it + b[*it]], t[x] + 1);
        par[*it + b[*it]] = make_pair(*it, x);
        Q.push(*it + b[*it]);
      }
      S.erase(it);
    }
  }
  cout << (t[inx] ? t[inx] : -1) << '\n';
  if (inx != -1) {
    vector<int> v;
    v.push_back(0);
    while (par[inx].first) {
      v.push_back(par[inx].first);
      inx = par[inx].second;
    }
    reverse(v.begin(), v.end());
    for (auto it : v) cout << it << ' ';
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int test_cases = 1;
  while (test_cases--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 123, inf = 1e9 + 1, mod = 2e11, MOD = 3e11;
const long long INF = 1e18;
int n, a[maxn];
void solve() {
  cin >> n;
  set<pair<int, int> > second;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > 0) second.insert({a[i], i});
  }
  vector<pair<int, int> > ans;
  pair<int, int> x = *second.begin();
  second.erase(x);
  while (!second.empty()) {
    pair<int, int> y = *second.rbegin();
    second.erase(y);
    ans.push_back(make_pair(x.second, y.second));
    x.first--;
    y.first--;
    if (y.first > 0) second.insert(y);
    if (second.empty()) break;
    if (x.first == 0) {
      x = *second.begin();
      second.erase(x);
    }
  }
  cout << ans.size() << endl;
  for (auto to : ans) cout << to.first << " " << to.second << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

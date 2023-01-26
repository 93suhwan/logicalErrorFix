#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
pair<int, int> a[200005];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i].second;
  string s;
  cin >> s;
  for (int i = 1; i <= n; ++i) a[i].first = (s[i - 1] == 'B' ? -1 : 1);
  sort(a + 1, a + n + 1);
  set<int> p;
  for (int i = 1; i <= n; ++i) p.insert(i);
  for (int i = 1; i <= n; ++i) {
    int id = a[i].first;
    if (id == -1) {
      int first = *p.begin();
      p.erase(first);
      if (first > a[i].second) {
        cout << "NO\n";
        return;
      }
    }
    if (id == 1) {
      auto u = p.lower_bound(a[i].second);
      if (u == p.end()) {
        cout << "NO\n";
        return;
      }
      p.erase(u);
    }
  }
  cout << "YES\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}

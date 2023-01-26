#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
struct pp {
  pair<int, int> p;
  int id;
} w[N];
int cmp(pp a, pp b) { return a.p.second < b.p.second; }
set<pair<int, int> > L, R;
set<int> win;
int ans[N];
void solve() {
  L.clear();
  R.clear();
  win.clear();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i].p.first);
    w[i].id = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i].p.second);
  }
  sort(w + 1, w + 1 + n, cmp);
  win.insert(w[n].p.first);
  ans[w[n].id] = 1;
  for (int i = 1; i <= n; i++) {
    L.insert(w[i].p);
  }
  for (int i = n - 1; i >= 1; i--) {
    if (w[i].p.first > *win.begin()) {
      win.insert(w[i].p.first);
      ans[w[i].id] = 1;
    } else {
      ans[w[i].id] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

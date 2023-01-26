#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
struct pp {
  pair<int, int> p;
  int id;
} w[N];
int cmp(pp a, pp b) { return a.p.second < b.p.second; }
set<int, greater<int> > los;
set<int, greater<int> > L;
int ans[N];
int n;
void solve() {
  L.clear();
  los.clear();
  cin >> n;
  sort(w + 1, w + 1 + n, cmp);
  int win = w[n].p.first;
  ans[w[n].id] = 1;
  for (int i = 1; i <= n - 1; i++) {
    L.insert(w[i].p.second);
  }
  for (int i = n - 1; i >= 1; i--) {
    if (w[i].p.first > win || *L.begin() > win) {
      win = min(win, w[i].p.first);
      ans[w[i].id] = 1;
      while (!los.empty()) {
        int x = *los.begin();
        if (w[i].p.first < x) {
          win = min(win, x);
          los.erase(los.begin());
        } else
          break;
      }
    } else {
      los.insert(w[i].p.first);
    }
    L.erase(w[i].p.second);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    solve();
    for (int i = 1; i <= n; i++) {
      scanf("%d", &w[i].p.first);
      w[i].id = i;
      ans[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &w[i].p.second);
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}

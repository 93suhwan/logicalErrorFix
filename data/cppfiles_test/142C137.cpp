#include <bits/stdc++.h>
using namespace std;
int m, n, mx[100005];
vector<vector<int> > p;
bool check(int x) {
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++)
      if (p[i][j] >= x) cnt++;
    if (cnt >= 2) return true;
  }
  return false;
}
void run() {
  cin >> m >> n;
  memset(mx, 0, sizeof(mx));
  p.resize(m);
  for (int i = 0; i < m; i++) {
    p[i].clear();
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      p[i].push_back(a);
      mx[j] = max(mx[j], a);
    }
  }
  int l = 0, r = 1e9, res;
  for (int i = 0; i < n; i++) r = min(r, mx[i]);
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      l = mid + 1;
      res = mid;
    } else
      r = mid - 1;
  }
  cout << res << endl;
}
int main() {
  int TT;
  cin >> TT;
  while (TT--) run();
  return 0;
}

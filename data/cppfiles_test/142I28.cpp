#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int inf = 0x3f;
vector<int> a[N];
int n, m;
bool check(int mid) {
  if (n <= m - 1) {
    for (int j = 0; j < m; j++) {
      int flag = 0;
      for (int i = 0; i < n; i++) {
        if (a[i][j] >= mid) flag++;
      }
      if (flag == 0) return 0;
    }
    return 1;
  } else {
    for (int i = 0; i < n; i++) {
      int flag = 0;
      for (int j = 0; j < m; j++) {
        if (a[i][j] >= mid) flag++;
      }
      if (flag >= 2) return 1;
    }
    return 0;
  }
}
void f() {
  int l = 0, r = inf;
  for (int j = 0; j < m; j++) {
    int maxn = 0;
    for (int i = 0; i < n; i++) {
      maxn = max(maxn, a[i][j]);
    }
    r = min(r, maxn);
  }
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << r << '\n';
  ;
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    a[i].clear();
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      a[i].push_back(x);
    }
  }
  f();
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long i, j;
  long long m, n;
  cin >> n >> m;
  set<long long> a[n + 4];
  bool status[n + 4];
  for (i = 1; i <= n; i++) status[i] = 1;
  long long ans = n;
  for (i = 0; i <= m - 1; i++) {
    long long x, y;
    cin >> x >> y;
    a[x].insert(y);
    a[y].insert(x);
    if (x < y && status[x] == 1) {
      status[x] = 0;
      ans--;
    }
    if (y < x && status[y] == 1) {
      status[y] = 0;
      ans--;
    }
  }
  long long q;
  cin >> q;
  for (j = 1; j <= q; j++) {
    long long type;
    cin >> type;
    if (type == 3) {
      cout << ans << "\n";
    }
    if (type == 2) {
      long long x, y;
      cin >> x >> y;
      a[x].erase(a[x].find(y));
      a[y].erase(a[y].find(x));
      if (a[x].empty()) {
        if (status[x] == 0) {
          status[x] = 1;
          ans++;
        }
        continue;
      }
      if (a[y].empty()) {
        if (status[y] == 0) {
          status[y] = 1;
          ans++;
        }
        continue;
      }
      auto max_it = a[x].end();
      max_it--;
      if (*max_it < x) {
        if (status[x] == 0) {
          status[x] = 1;
          ans++;
        }
      }
      auto max_it_y = a[y].end();
      max_it_y--;
      if (*max_it_y < y && status[y] == 0) {
        status[y] = 1;
        ans++;
      }
    }
    if (type == 1) {
      long long x, y;
      cin >> x >> y;
      a[x].insert(y);
      a[y].insert(x);
      if (x < y && status[x] == 1) {
        status[x] = 0;
        ans--;
      }
      if (y < x && status[y] == 1) {
        status[y] = 0;
        ans--;
      }
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
struct point {
  int id;
  bool ok;
  int row;
  bool operator<(const point &p) const {
    return (id == p.id) ? ok < p.ok : id < p.id;
  }
};
point a[600100];
vector<int> edge[300100];
int dp[300100];
int truoc[300100];
bool ok[300100];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    a[i << 1] = {y, 1, x};
    a[i << 1 | 1] = {z + 1, 0, x};
  }
  sort(a, a + 2 * m);
  multiset<int, greater<int> > b;
  multiset<int> c;
  for (int i = 0; i < 2 * m; i++) {
    if (a[i].ok) {
      if (b.upper_bound(a[i].row) != b.end()) {
        edge[*b.upper_bound(a[i].row)].push_back(a[i].row);
      }
      if (c.upper_bound(a[i].row) != c.end()) {
        edge[a[i].row].push_back(*c.upper_bound(a[i].row));
      }
      b.insert(a[i].row);
      c.insert(a[i].row);
    } else {
      b.erase(b.find(a[i].row));
      c.erase(c.find(a[i].row));
    }
  }
  for (int i = 1; i < n; i++) {
    dp[i] = max(dp[i], 1);
    for (auto x : edge[i]) {
      if (dp[x] < dp[i] + 1) {
        dp[x] = dp[i] + 1;
        truoc[x] = i;
      }
    }
  }
  int max1 = -1;
  int id;
  for (int i = 1; i <= n; i++) {
    if (dp[i] > max1) {
      max1 = dp[i];
      id = i;
    }
  }
  cout << n - max1 << '\n';
  int cur = id;
  while (cur != 0) {
    ok[cur] = 1;
    cur = truoc[cur];
  }
  for (int i = 1; i <= n; i++) {
    if (!ok[i]) {
      cout << i << ' ';
    }
  }
  return 0;
}

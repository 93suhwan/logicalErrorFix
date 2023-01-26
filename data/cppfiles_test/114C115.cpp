#include <bits/stdc++.h>
using namespace std;
const int kmax = 2e5 + 3;
int n, m, a[15][kmax], c[kmax], h;
struct Node {
  int a[15];
  bool operator<(const Node &pp) const {
    for (int i = 1; i <= n; i++) {
      if (a[i] != pp.a[i]) {
        return a[i] > pp.a[i];
      }
    }
    return 0;
  }
} b[kmax], d, e;
struct E {
  Node f;
  int g;
  bool operator<(const E &ll) const { return g < ll.g; }
};
map<Node, bool> mp, v;
priority_queue<E> q;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    for (int j = 1; j <= c[i]; j++) {
      cin >> a[i][j];
    }
    d.a[i] = c[i];
    h += a[i][c[i]];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> b[i].a[j];
    }
    mp[b[i]] = 1;
  }
  for (q.push((E){d, h}), v[d] = 1; !q.empty(); q.pop()) {
    E x = q.top();
    if (!mp[x.f]) {
      for (int i = 1; i <= n; i++) {
        cout << x.f.a[i] << ' ';
      }
      return 0;
    }
    e = x.f;
    for (int i = 1; i <= n; i++) {
      if (e.a[i] > 1) {
        e.a[i]--;
        if (!v[e]) {
          q.push((E){e, x.g + a[i][e.a[i]] - a[i][e.a[i] + 1]});
          v[e] = 1;
        }
        e.a[i]++;
      }
    }
  }
  return 0;
}

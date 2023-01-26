#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Node {
  int a, b, m, id;
  bool operator<(const Node& t) const { return a + b - m < t.a + t.b - t.m; }
} q[N];
pair<pair<int, int>, int> p[N];
int tt;
int a[N], b[N], m[N], res_a[N];
int main() {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i] >> m[i];
      q[i] = {a[i], b[i], m[i], i};
    }
    sort(q, q + n);
    int j = 0, res = 0;
    while (j < n) {
      tt = 0;
      p[tt++] = {{max(q[j].a - q[j].m, 0), q[j].a}, q[j].id};
      j++;
      while (j < n &&
             q[j].a + q[j].b - q[j].m == q[j - 1].a + q[j - 1].b - q[j - 1].m) {
        p[tt++] = {{max(q[j].a - q[j].m, 0), q[j].a}, q[j].id};
        j++;
      }
      int cur = 1e9;
      for (int i = tt - 1; i >= 0; --i) {
        if (cur > p[i].first.second) {
          cur = p[i].first.first;
          res++;
        }
        res_a[p[i].second] = cur;
      }
    }
    cout << res << endl;
    for (int i = 0; i < n; ++i)
      cout << a[i] - res_a[i] << ' ' << m[i] - (a[i] - res_a[i]) << endl;
  }
  return 0;
}

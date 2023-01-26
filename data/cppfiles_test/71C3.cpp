#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
using ftype = double;
struct pt {
  long long x, y;
  pt(long long x = 0, long long y = 0) : x(x), y(y) {}
  ftype dist() const { return hypotl(x, y); }
  pt operator-(const pt &o) const { return pt(x - o.x, y - o.y); }
  long long cross(const pt &o) const { return x * o.y - y * o.x; }
  long long dot(const pt &o) const { return x * o.x + y * o.y; }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(8);
  int n, k;
  cin >> n >> k;
  k--;
  vector<pt> p(n);
  for (int i = (0); i < (n); i++) cin >> p[i].x >> p[i].y;
  int a = 0, b = 1;
  int cnt = 0;
  for (int i = (0); i < (n); i++) {
    if ((p[i] - p[a]).cross(p[b] - p[a]) == 0) {
      cnt++;
    }
  }
  if (cnt < n - 1) b = 2;
  cnt = 0;
  for (int i = (0); i < (n); i++) {
    if ((p[i] - p[a]).cross(p[b] - p[a]) == 0) {
      cnt++;
    }
  }
  if (cnt < n - 1) a = 1;
  vector<int> ve1, ve2;
  for (int i = (0); i < (n); i++) {
    if ((p[i] - p[a]).cross(p[b] - p[a]) != 0) {
      ve1.push_back(i);
    } else {
      ve2.push_back(i);
    }
  }
  assert(((int)(ve1).size()) == 1);
  sort((ve2).begin(), (ve2).end(),
       [&](int i, int j) { return (p[i] - p[j]).dot(p[b] - p[a]) < 0; });
  vector<int> v;
  ftype ans = DBL_MAX;
  if (k != ve1[0]) {
    ans = min(ans, (p[k] - p[ve2[0]]).dist() +
                       (p[ve2[0]] - p[ve2.back()]).dist() +
                       (p[ve2.back()] - p[ve1[0]]).dist());
    ans = min(ans, (p[k] - p[ve2.back()]).dist() +
                       (p[ve2[0]] - p[ve2.back()]).dist() +
                       (p[ve2[0]] - p[ve1[0]]).dist());
  } else {
    ans = min(ans,
              (p[k] - p[ve2[0]]).dist() + (p[ve2[0]] - p[ve2.back()]).dist());
    ans = min(ans, (p[k] - p[ve2.back()]).dist() +
                       (p[ve2[0]] - p[ve2.back()]).dist());
    cout << ans << '\n';
    return 0;
  }
  vector<vector<int>> kys = {
      {0, 1, 2, 3, 4, 5}, {0, 2, 1, 3, 4, 5}, {0, 1, 2, 3, 5, 4},
      {0, 2, 1, 3, 5, 4}, {0, 4, 5, 3, 1, 2}, {0, 5, 4, 3, 1, 2},
      {0, 4, 5, 3, 2, 1}, {0, 5, 4, 3, 2, 1},
  };
  v.resize(6);
  v[0] = k;
  v[1] = ve2[0];
  v[3] = ve1[0];
  v[5] = ve2.back();
  for (int j = (1); j < (((int)(ve2).size())); j++) {
    v[2] = ve2[j - 1];
    v[4] = ve2[j];
    for (int perm = (0); perm < (((int)(kys).size())); perm++) {
      ftype dist = 0;
      for (int i = (1); i < (6); i++) {
        dist += (p[v[kys[perm][i]]] - p[v[kys[perm][i - 1]]]).dist();
      }
      ans = min(ans, dist);
    }
  }
  cout << ans << '\n';
}

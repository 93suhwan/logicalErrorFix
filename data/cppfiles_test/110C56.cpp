#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 1e9;
struct P {
  int x, y, c;
} p[N];
int n, ans, R[5];
void sol1(vector<int>& v) {
  int l = 1, r = n / 3, f = 0;
  while (l <= r) {
    int mid = (l + r) >> 1, j = 0, k = 0;
    for (int i = 0; i < n && j < 3; i++)
      if (v[j] == p[i].c && ++k == mid) ++j, k = 0;
    if (j == 3)
      l = mid + 1, f = mid;
    else
      r = mid - 1;
  }
  ans = max(ans, 3 * f);
}
void sol2(int q) {
  int a, b;
  if (q == 1) a = 2, b = 3;
  if (q == 2) a = 1, b = 3;
  if (q == 3) a = 1, b = 2;
  int l = 1, r = n / 3, f = 0;
  while (l <= r) {
    int mid = (l + r) >> 1, s = n, k = 0;
    for (int i = 0; i < n; i++)
      if (p[i].c == q && ++k == mid) {
        s = i + 1;
        break;
      }
    vector<P> v;
    for (int i = s; i < n; i++)
      if (p[i].c != q) v.push_back(p[i]);
    sort(v.begin(), v.end(), [&](P a, P b) { return a.y < b.y; });
    int la = inf, ra = -inf, lb = inf, rb = -inf, t = 0;
    for (auto& it : v)
      if (it.c == a && ++t == mid) {
        la = it.y;
        break;
      }
    t = 0;
    for (auto& it : v)
      if (it.c == b && ++t == mid) {
        lb = it.y;
        break;
      }
    reverse(v.begin(), v.end());
    t = 0;
    for (auto& it : v)
      if (it.c == a && ++t == mid) {
        ra = it.y;
        break;
      }
    t = 0;
    for (auto& it : v)
      if (it.c == b && ++t == mid) {
        rb = it.y;
        break;
      }
    if (la < rb || lb < ra)
      l = mid + 1, f = mid;
    else
      r = mid - 1;
  }
  ans = max(ans, 3 * f);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].c);
  for (int i = 0; i < 4; i++) {
    if (i < 2) {
      vector<int> v = {1, 2, 3};
      do {
        for (int i = 0; i < 3; i++) R[v[i]] = i;
        sort(p, p + n, [&](P a, P b) {
          if (a.x == b.x) return R[a.c] > R[b.c];
          return a.x < b.x;
        });
        sol1(v);
      } while (next_permutation(v.begin(), v.end()));
    }
    for (int j = 1; j <= 3; j++) {
      sort(p, p + n, [&](P a, P b) {
        if (a.x == b.x) return (a.c == j) < (b.c == j);
        return a.x < b.x;
      });
      sol2(j);
    }
    for (int j = 0; j < n; j++) p[j] = {p[j].y, n - p[j].x - 1, p[j].c};
  }
  printf("%d\n", ans);
  return 0;
}

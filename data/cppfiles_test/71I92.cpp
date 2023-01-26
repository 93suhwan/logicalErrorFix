#include <bits/stdc++.h>
using namespace std;
const int DIM = 2e5 + 5;
struct point {
  int x, y;
  point() : x(0), y(0){};
};
bool colinear(point a, point b, point c) {
  if (1LL * (a.x - b.x) * (a.y - c.y) == 1LL * (a.x - c.x) * (a.y - b.y)) {
    if (a.x - b.x == 0) {
      if (a.x - c.x == 0) return true;
      return false;
    }
    if (a.y - b.y == 0) {
      if (a.y - c.y == 0) return true;
      return false;
    }
    return true;
  }
  return false;
}
long double dist(point a, point b) {
  return sqrt((long double)(a.x - b.x) * (a.x - b.x) +
              (long double)(a.y - b.y) * (a.y - b.y));
}
int n, k;
point a[DIM];
vector<int> get_pair(int x, int y) {
  auto X = a[x];
  auto Y = a[y];
  vector<int> sol;
  sol.push_back(x);
  sol.push_back(y);
  for (int i = 1; i <= n; ++i) {
    if (i == x || i == y) continue;
    if (colinear(X, Y, a[i])) sol.push_back(i);
  }
  return sol;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i].x, &a[i].y);
  }
  vector<int> ind = get_pair(1, 2);
  if ((int)ind.size() != n - 1) ind = get_pair(3, 4);
  sort(ind.begin(), ind.end(), [](int x, int y) {
    if (a[x].x != a[y].x) return a[x].x < a[y].x;
    return a[x].y < a[y].y;
  });
  bool found = false;
  vector<int> ap(n + 1, 0);
  for (auto it : ind) {
    ap[it] = true;
    if (it == k) found = true;
  }
  point out;
  for (int i = 1; i <= n; ++i)
    if (!ap[i]) out = a[i];
  long double ans = 1e18;
  if (!found) {
    ans = dist(a[ind[0]], a[ind.back()]) +
          min(dist(a[ind[0]], a[k]), dist(a[ind.back()], a[k]));
  } else {
    long double pref = 0, suf = 0;
    bool type = 0;
    int wh = -1;
    for (int i = 0; i < (int)ind.size(); ++i) {
      auto it = ind[i];
      if (it == k)
        wh = i, type = 1;
      else if (i > 0 && type == 0)
        pref = pref + dist(a[ind[i] - 1], a[it]);
      else {
        if (i > 0) suf = suf + dist(a[ind[i] - 1], a[it]);
      }
    }
    if (wh + 1 < (int)ind.size())
      ans = min(ans,
                pref + suf + dist(a[ind[0]], out) +
                    min(dist(a[ind[wh + 1]], out), dist(a[ind.back()], out)));
    else
      ans = min(ans, pref + suf + dist(a[ind[0]], out));
    if (wh - 1 > 0)
      ans = min(ans, pref + suf + dist(a[ind.back()], out) +
                         min(dist(a[ind[wh - 1]], out), dist(a[ind[0]], out)));
    else
      ans = min(ans, pref + suf + dist(a[ind.back()], out));
  }
  printf("%0.9Lf", ans);
  return 0;
}

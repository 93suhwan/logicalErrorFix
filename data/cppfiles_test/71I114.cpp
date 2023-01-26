#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
struct point {
  int x;
  int y;
  double dist(const point& a) const { return hypot(a.x - x, a.y - y); }
};
bool operator<(const point& lhs, const point& rhs) {
  return make_tuple(lhs.x, lhs.y) < make_tuple(rhs.x, rhs.y);
}
bool operator==(const point& lhs, const point& rhs) {
  return make_tuple(lhs.x, lhs.y) == make_tuple(rhs.x, rhs.y);
}
void solve() {
  int n, k;
  cin >> n >> k;
  k--;
  vector<point> p(n);
  for (auto& i : p) {
    cin >> i.x >> i.y;
  }
  auto fixed = p[k];
  sort(p.begin(), p.end());
  map<int, int> Mcnt;
  for (int i = 0; i + 2 < n; ++i) {
    if (fabs(p[i].dist(p[i + 1]) + p[i + 2].dist(p[i + 1]) -
             p[i].dist(p[i + 2])) > eps) {
      for (int j = 0; j < 3; ++j) {
        Mcnt[i + j]++;
      }
    }
  }
  int mx = 0;
  for (auto e : Mcnt) {
    mx = max(mx, e.second);
  }
  switch (mx) {
    case 1: {
      if (Mcnt[0] == 1) {
        swap(p[0], p.back());
      }
      break;
    }
    case 2: {
      if (Mcnt[1] == 2) {
        swap(p[1], p.back());
      } else {
        swap(p[n - 2], p.back());
      }
      break;
    }
    case 3: {
      for (auto e : Mcnt) {
        if (e.second == 3) {
          swap(p.back(), p[e.first]);
          break;
        }
      }
      break;
    }
    default:
      break;
  }
  sort(p.begin(), p.begin() + n - 1);
  vector<double> pref(n);
  pref[0] = 0;
  for (int i = 1; i < n; ++i) {
    pref[i] = pref[i - 1] + p[i - 1].dist(p[i]);
  }
  double res = 1e9;
  if (p.back() == fixed) {
    res = pref.back() + min(p.back().dist(p[0]), p.back().dist(p[n - 2]));
  } else {
    auto dist = [&](const int lhs, const int rhs) {
      return fabs(pref[rhs] - pref[lhs]);
    };
    for (int i = 0; i < n; i++) {
      if (p[i] == fixed) {
        k = i;
      }
    }
    for (int i = 0; i <= n - 2; ++i) {
      if (true) {
        double v1 = dist(k, 0) + dist(0, i) + p[i].dist(p.back()) +
                    (i + 1 > n - 2 ? 0 : p[i + 1].dist(p.back())) +
                    (i + 1 > n - 1 ? 0 : dist(i + 1, n - 2));
        double v2 = dist(k, i) + dist(0, i) + p[0].dist(p.back()) +
                    (i + 1 > n - 2 ? 0 : p[i + 1].dist(p.back())) +
                    (i + 1 > n - 1 ? 0 : dist(i + 1, n - 2));
        res = min(res, min(v1, v2));
      }
      if (true) {
        double v1 = dist(k, n - 2) + dist(n - 2, i) + p[i].dist(p.back()) +
                    (i > 0 ? p[i - 1].dist(p.back()) : 0) +
                    (i > 1 ? dist(i - 1, 0) : 0);
        double v2 = dist(k, i) + dist(n - 2, i) + p[n - 2].dist(p.back()) +
                    (i > 0 ? p[i - 1].dist(p.back()) : 0) +
                    (i > 1 ? dist(i - 1, 0) : 0);
        res = min(res, min(v1, v2));
      }
    }
  }
  cout << std::fixed << setprecision(10) << res << "\n";
}
int main() {
  solve();
  return 0;
}

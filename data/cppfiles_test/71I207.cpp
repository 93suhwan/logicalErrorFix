#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

struct pt {
  ll x, y;

  pt(ll x, ll y) : x(x), y(y) {}

  pt() = default;
};

pt operator-(const pt &a, const pt &b) {
  return pt(a.x - b.x, a.y - b.y);
}

bool operator==(const pt &a, const pt &b) {
  return a.x == b.x && a.y == b.y;
}

struct line {
  ll a, b, c;

  line(const pt &p, const pt &q) {
    a = q.y - p.y;
    b = p.x - q.x;
    c = -(a * p.x + b * p.y);
  }

  bool lies(const pt &p) {
    return a * p.x + b * p.y + c == 0;
  }
};

ld dist(const pt &a, const pt &b) {
  return hypot(a.x - b.x, a.y - b.y);
}

ld subSolve(const vector<pt> &pts, optional<pt> other) {
  ld all = 0;
  for (int i = 0; i + 1 < (int) pts.size(); i++) {
    all += dist(pts[i], pts[i + 1]);
  }
  if (other) {
    ld res = all + dist(pts[0], *other);
    res = min(res, all + dist(pts.back(), *other));
    for (int i = 0; i + 1 < (int) pts.size(); i++) {
      res = min(res, all - dist(pts[i], pts[i + 1]) + dist(pts[i], *other) + dist(*other, pts[i + 1]));
    }
    return res;
  } else {
    return all;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(20);
  cout << fixed;

  int n, k;
  cin >> n >> k;
  --k;
  vector<pt> pts(n);
  for (int i = 0; i < n; i++) {
    cin >> pts[i].x >> pts[i].y;
  }
  ld res = 1e18;
  for (line l: vector<line>{line(pts[0], pts[1]), line(pts[0], pts[2]), line(pts[1], pts[2])}) {
    vector<pt> onLine;
    optional<pt> other;
    for (const pt &p: pts) {
      if (l.lies(p)) {
        onLine.push_back(p);
      } else {
        other = p;
      }
    }
    if (onLine.size() >= n - 1) {
      sort(onLine.begin(), onLine.end(), [](const pt &a, const pt &b) {
        return pair<ll, ll>(a.x, a.y) < pair<ll, ll>(b.x, b.y);
      });
      vector<pt> order1;
      vector<pt> order2;
      for (int i = 0; i < (int) onLine.size(); i++) {
        if (pts[k] == onLine[i]) {
          order1.insert(order1.end(), onLine.begin() + i, onLine.end());
          order1.insert(order1.end(), onLine.begin(), onLine.begin() + i);
          order2.insert(order2.end(), onLine.begin(), onLine.begin() + i + 1);
          reverse(order2.begin(), order2.end());
          order2.insert(order2.end(), onLine.begin() + i + 1, onLine.end());
          break;
        }
      }
      res = min(res, subSolve(order1, other));
      res = min(res, subSolve(order2, other));
    }
  }

  cout << res;
  return 0;
}

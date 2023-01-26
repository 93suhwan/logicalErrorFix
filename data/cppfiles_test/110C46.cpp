#include <bits/stdc++.h>
using namespace std;
const int iinf = 1e9 + 10;
const long long inf = 1ll << 60;
const long long mod = 1e9 + 7;
void GG() {
  cout << "0\n";
  exit(0);
}
long long mpow(long long a, long long n, long long mo = mod) {
  long long re = 1;
  while (n > 0) {
    if (n & 1) re = re * a % mo;
    a = a * a % mo;
    n >>= 1;
  }
  return re;
}
long long inv(long long b, long long mo = mod) {
  if (b == 1) return b;
  return (mo - mo / b) * inv(mo % b, mo) % mo;
}
const int maxn = 2e5 + 5;
struct pt {
  int x, y, c;
};
vector<int> xpos, ypos;
long long get(vector<pt> v, int top, int dl, int dr) {
  sort(v.begin(), v.end(), [&](pt a, pt b) {
    return (a.x != b.x) ? (a.x < b.x) : ((a.c == dl) < (b.c == dl));
  });
  vector<pt> vy = v;
  sort(vy.begin(), vy.end(), [&](pt a, pt b) {
    return (a.y != b.y) ? (a.y < b.y) : ((a.c == dl) < (b.c == dl));
  });
  auto get = [&](int Y, vector<pt> &VV) {
    int numr = 0;
    for (pt p : VV) {
      if (p.y < Y) {
        if (p.c == dr) ++numr;
      }
    }
    int numl = 0;
    int re = 0;
    for (pt p : VV) {
      if (p.y < Y) {
        if (p.c == dr) --numr;
        if (p.c == dl) ++numl;
        re = max(re, (__typeof__(re))(min(numr, numl)));
      }
    }
    return re;
  };
  assert((int)vy.size() != 0);
  int l = vy[0].y, r = vy.back().y;
  ;
  int ret = 0;
  while (l != r) {
    int mid = (l + r) / 2 - (((l + r) % 2) && ((l + r) < 0));
    int topans = max(get(mid, v), get(mid, vy));
    int tt = 0;
    for (pt p : v) {
      if (p.y >= mid) {
        if (p.c == top) ++tt;
      }
    }
    ret = max(ret, (__typeof__(ret))(min(tt, topans)));
    if (tt >= topans) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  {
    int topans = max(get(l, v), get(l, vy));
    int tt = 0;
    for (pt p : v) {
      if (p.y >= l) {
        if (p.c == top) ++tt;
      }
    }
    ret = max(ret, (__typeof__(ret))(min(tt, topans)));
  }
  return ret;
}
int gocut(vector<pt> &v) {
  vector<int> hm = {1, 2, 3};
  int re = 0;
  do {
    re = max(re, (__typeof__(re))(get(v, hm[0], hm[1], hm[2])));
  } while (next_permutation(hm.begin(), hm.end()));
  return re;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n;
  cin >> n;
  vector<pt> v;
  for (int i = 0; i < n; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    v.push_back({x, y, c});
    xpos.push_back(x);
    ypos.push_back(y);
  }
  (sort(xpos.begin(), xpos.end()),
   xpos.resize(distance(xpos.begin(), unique(xpos.begin(), xpos.end()))));
  (sort(ypos.begin(), ypos.end()),
   ypos.resize(distance(ypos.begin(), unique(ypos.begin(), ypos.end()))));
  for (int i = 0; i < n; ++i) {
    v[i].x = lower_bound(xpos.begin(), xpos.end(), v[i].x) - xpos.begin();
    v[i].y = lower_bound(ypos.begin(), ypos.end(), v[i].y) - ypos.begin();
  }
  int re = 0;
  for (int r = 0; r < 4; ++r) {
    re = max(re, (__typeof__(re))(gocut(v)));
    for (pt &p : v) {
      int nx = -p.y;
      int ny = p.x;
      p.x = nx;
      p.y = ny;
    }
  }
  cout << re * 3 << '\n';
}

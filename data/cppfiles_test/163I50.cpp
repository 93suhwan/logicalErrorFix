#include <bits/stdc++.h>
using namespace std;
const int siz1 = 2e5, siz2 = 30, mod = 1e9 + 7;
const double eps = 1e-7;
int t, n, m, rb, cb, rd, cd, p;
set<pair<pair<int, int>, pair<int, int>>> ps;
vector<int> ts;
int add(int a, int b) { return (a + b) % mod; }
int sub(int a, int b) { return (a - b + mod) % mod; }
int mul(int a, int b) { return ((long long)a * b) % mod; }
int powmod(int a, int b) {
  if (b == 0) {
    return 1;
  }
  int p = powmod(a, b / 2);
  p = mul(p, p);
  return (b & 1) ? mul(p, a) : p;
}
void clear() {
  ps.clear();
  ts.clear();
}
int divi(int a, int b) { return mul(a, powmod(b, mod - 2)); }
int getdist(int src, int dest, int dir, int lim) {
  if (dir == 1) {
    if (dest >= src) {
      return dest - src;
    }
    return (lim - src) * 2 + src - dest;
  } else {
    if (dest <= src) {
      return src - dest;
    }
    return (src - 1) * 2 + dest - src;
  }
}
int move(int a, int b, int &dir, int lim) {
  b *= dir;
  if (a + b >= lim) {
    b = abs(b);
    dir = -dir;
    return lim - (b - (lim - a));
  } else if (a + b <= 1) {
    b = abs(b);
    dir = -dir;
    return 1 + (b - (a - 1));
  }
  return a + b;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d%d%d%d", &n, &m, &rb, &cb, &rd, &cd, &p);
    p = divi(p, 100);
    pair<int, int> cur = {rb, cb};
    pair<int, int> dir = {1, 1};
    int tim = 0, cycle_tim = 0;
    while (1) {
      int rdist = getdist(cur.first, rd, dir.first, n);
      int cdist = getdist(cur.second, cd, dir.second, m);
      int tomove = min(rdist, cdist);
      cur.first = move(cur.first, tomove, dir.first, n);
      cur.second = move(cur.second, tomove, dir.second, m);
      tim = add(tim, tomove);
      cycle_tim = tim;
      if (ps.count({cur, dir})) {
        break;
      }
      ps.insert({cur, dir});
      ts.push_back(tim);
      cur.first = move(cur.first, 1, dir.first, n);
      cur.second = move(cur.second, 1, dir.second, m);
      tim = add(tim, 1);
    }
    cycle_tim = sub(cycle_tim, ts[0]);
    int psub = sub(1, p);
    int p1all = powmod(psub, ts.size());
    int p2all = divi(1, sub(1, p1all));
    int ans = 0;
    int psub_all = 1;
    for (const auto &tim : ts) {
      ans = add(
          ans, mul(psub_all,
                   mul(p, add(mul(tim, p2all),
                              mul(cycle_tim, sub(mul(p2all, p2all), p2all))))));
      psub_all = mul(psub_all, psub);
    }
    printf("%d\n", ans);
    clear();
  }
  return 0;
}

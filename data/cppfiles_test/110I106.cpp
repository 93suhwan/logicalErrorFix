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
const int maxn = 1e5 + 5;
int m1[maxn * 4], m2[maxn * 4], mx[maxn * 4], v1[maxn * 4], v2[maxn * 4];
void push(int o, int l, int r) {
  if (v1[o]) {
    m1[o] += v1[o];
    if (l != r) {
      v1[o * 2] += v1[o];
      v1[o * 2 + 1] += v1[o];
    }
    v1[o] = 0;
  }
  if (v2[o]) {
    m2[o] += v2[o];
    if (l != r) {
      v2[o * 2] += v2[o];
      v2[o * 2 + 1] += v2[o];
    }
    v2[o] = 0;
  }
  mx[o] = max(mx[o], (__typeof__(mx[o]))(min(m1[o], m2[o])));
}
void MO(int L, int R, long long v, bool go1, int o = 1, int l = 0,
        int r = maxn - 1) {
  push(o, l, r);
  if (l > R || r < L) return;
  if (l >= L && r <= R) {
    (go1 ? v1[o] : v2[o]) += v;
    push(o, l, r);
    return;
  }
  int mid = (l + r) / 2;
  MO(L, R, v, go1, o * 2, l, mid);
  MO(L, R, v, go1, o * 2 + 1, mid + 1, r);
  m1[o] = max(m1[o * 2], m1[o * 2 + 1]);
  m2[o] = max(m2[o * 2], m2[o * 2 + 1]);
  mx[o] = max(mx[o], (__typeof__(mx[o]))(max(mx[o * 2], mx[o * 2 + 1])));
}
struct pt {
  int x, y, c;
};
int run(vector<pt> v, int lp, int rp, int top) {
  memset(mx, 0, sizeof mx);
  memset(v1, 0, sizeof v1);
  memset(v2, 0, sizeof v2);
  memset(m1, 0, sizeof m1);
  memset(m2, 0, sizeof m2);
  sort(v.begin(), v.end(), [&](pt a, pt b) {
    if (a.y != b.y) return a.y < b.y;
    return (a.c == top) < (b.c == top);
  });
  int re = 0;
  int tcnt = (int)v.size() / 3;
  for (pt p : v) {
    if (p.c == top) {
      --tcnt;
    } else if (p.c == lp) {
      MO(0, p.x, 1, 0);
    } else {
      MO(p.x, maxn - 1, 1, 1);
    }
    re = max(re, (__typeof__(re))(min(tcnt, mx[1])));
    if (tcnt <= mx[1]) break;
  }
  return re;
}
int go(vector<pt> &v) {
  vector<int> yay = {1, 2, 3};
  int re = 0;
  do {
    re = max(re, run(v, yay[0], yay[1], yay[2]));
  } while (next_permutation(yay.begin(), yay.end()));
  return re;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n;
  cin >> n;
  vector<pt> v;
  vector<int> xpos;
  for (int i = 0; i < n; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    v.push_back({x, y, c});
    xpos.push_back(x);
  }
  (sort(xpos.begin(), xpos.end()),
   xpos.resize(distance(xpos.begin(), unique(xpos.begin(), xpos.end()))));
  for (int i = 0; i < n; ++i) {
    v[i].x = lower_bound(xpos.begin(), xpos.end(), v[i].x) - xpos.begin();
  }
  int g1 = go(v);
  for (int i = 0; i < n; ++i) v[i].y = -v[i].y;
  int g2 = go(v);
  cout << max(g1, g2) * 3 << '\n';
}

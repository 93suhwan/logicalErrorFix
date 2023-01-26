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
int na[maxn * 4], nb[maxn * 4];
void MO(int p, int v, bool go1, int o = 1, int l = 0, int r = maxn - 1) {
  if (l > p || r < p) return;
  (go1 ? na : nb)[o]++;
  if (l == r) {
    return;
  }
  int mid = (l + r) / 2;
  MO(p, v, go1, o * 2, l, mid);
  MO(p, v, go1, o * 2 + 1, mid + 1, r);
}
int ptoo[maxn];
void build(int o = 1, int l = 0, int r = maxn - 1) {
  if (l == r) {
    ptoo[l] = o;
    return;
  }
  int mid = (l + r) / 2;
  build(o * 2, l, mid);
  build(o * 2 + 1, mid + 1, r);
}
int QU(int o, int l, int r, int havea, int haveb, int Tb) {
  if (l == r) {
    return min(havea + na[o], Tb - (haveb + nb[o]));
  }
  int rar = havea + na[o];
  int bar = Tb - (haveb + nb[o]);
  int to = min(rar, bar);
  int mid = (l + r) / 2;
  if (rar <= bar) {
    return max(to, QU(o * 2 + 1, mid + 1, r, havea + na[o], haveb + nb[o], Tb));
  } else {
    return max(to, QU(o * 2, l, mid, havea, haveb, Tb));
  }
}
struct pt {
  int x, y, c;
};
int run(vector<pt> v, int lp, int rp, int top) {
  memset(na, 0, sizeof na);
  memset(nb, 0, sizeof nb);
  sort(v.begin(), v.end(), [&](pt a, pt b) {
    if (a.y != b.y) return a.y < b.y;
    return (a.c == top) < (b.c == top);
  });
  int re = 0;
  int tcnt = (int)v.size() / 3;
  int tb = 0;
  for (pt p : v) {
    if (p.c == top) {
      --tcnt;
    } else if (p.c == lp) {
      MO(p.x, 1, 0);
      tb++;
    } else {
      MO(p.x, 1, 1);
    }
    int qq = QU(1, 0, maxn - 1, 0, 0, tb);
    re = max(re, (__typeof__(re))(min(tcnt, qq)));
    if (tcnt <= qq) break;
  }
  return re;
}
int go(vector<pt> &v) {
  vector<int> yay = {1, 2, 3};
  int re = 0;
  do {
    ;
    re = max(re, run(v, yay[0], yay[1], yay[2]));
  } while (next_permutation(yay.begin(), yay.end()));
  return re;
}
int yar(vector<pt> &v) {
  int g1 = go(v);
  for (int i = 0; i < (int)v.size(); ++i) v[i].y = -v[i].y;
  int g2 = go(v);
  return max(g1, g2);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n;
  cin >> n;
  vector<pt> v;
  vector<int> xpos, ypos;
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
  int g1 = yar(v);
  for (int i = 0; i < n; ++i) swap(v[i].x, v[i].y);
  int g2 = yar(v);
  cout << max(g1, g2) * 3 << '\n';
}

#include <bits/stdc++.h>
using namespace std;
long long T, a, b, c, o, h[1000001], d[1000001], cn,
    mod = 1000000007, mx[1000001], la[1000001], an[1000001];
long long v[1000001], f[1000001];
string s, s1, s2;
struct p {
  long long v, la;
} l[2000001];
vector<long long> qu[1000001];
long long gcd(long long qq, long long ww) {
  if (!ww) return qq;
  return gcd(ww, qq % ww);
}
long long pow_(long long qq, long long ww) {
  long long ee = 1;
  while (ww) {
    if (ww & 1) {
      ee *= qq;
      ee %= mod;
    }
    qq *= qq;
    qq %= mod;
    ww >>= 1;
  }
  return ee % mod;
}
void pushup(long long qq) {
  if (l[qq << 1].v < l[qq << 1 | 1].v)
    l[qq].la = l[qq << 1].la;
  else
    l[qq].la = l[qq << 1 | 1].la;
  l[qq].v = min(l[qq << 1].v, l[qq << 1 | 1].v);
}
void build(long long x, long long ll, long long rr) {
  if (ll == rr) {
    l[x].v = 10000000000;
    l[x].la = ll;
    return;
  }
  long long mid = ((ll + rr) >> 1);
  build(x << 1, ll, mid);
  build(x << 1 | 1, mid + 1, rr);
  pushup(x);
}
void change(long long x, long long ll, long long rr, long long qq,
            long long ww) {
  if (ll == rr) {
    l[x].v = ww;
    return;
  }
  long long mid = ((ll + rr) >> 1);
  if (mid >= qq)
    change(x << 1, ll, mid, qq, ww);
  else
    change(x << 1 | 1, mid + 1, rr, qq, ww);
  pushup(x);
}
p query(long long x, long long ll, long long rr, long long qq, long long ww) {
  if (ll >= qq && rr <= ww) {
    return l[x];
  }
  long long mid = ((ll + rr) >> 1);
  if (mid >= ww) return query(x << 1, ll, mid, qq, ww);
  if (mid < qq) return query(x << 1 | 1, mid + 1, rr, qq, ww);
  p q1 = query(x << 1, ll, mid, qq, ww),
    q2 = query(x << 1 | 1, mid + 1, rr, qq, ww);
  if (q1.v < q2.v) {
    return q1;
  }
  return q2;
}
int main() {
  T = 1;
  for (int ii = 1; ii <= T; ii++) {
    cn = 0;
    scanf("%lld", &a);
    qu[0].clear();
    for (int i = 1; i <= a; i++) {
      qu[i].clear();
      scanf("%lld", &d[i]);
    }
    for (int i = 1; i <= a; i++) {
      scanf("%lld", &f[i]);
      qu[i + f[i]].push_back(i);
      mx[i] = max(mx[i - 1], f[i]);
    }
    build(1, 1, a);
    for (int i = 1; i <= a; i++) {
      if (d[i] >= i) {
        la[i] = 0;
        for (int j = 0; j < qu[i].size(); j++) {
          change(1, 1, a, qu[i][j], 1);
        }
      } else {
        p qq = query(1, 1, a, max(i - d[i], (long long)(1)), i);
        la[i] = qq.la;
        for (int j = 0; j < qu[i].size(); j++) {
          change(1, 1, a, qu[i][j], qq.v + 1);
        }
      }
    }
    p gg = query(1, 1, a, a, a);
    if (gg.v >= 100000000) {
      printf("-1");
      return 0;
    }
    long long tt = a;
    while (tt) {
      tt = la[tt];
      an[++cn] = tt;
      tt += f[tt];
    }
    printf("%lld\n", cn);
    for (int i = 1; i <= cn; i++) {
      printf("%lld ", an[i]);
    }
  }
  return 0;
}

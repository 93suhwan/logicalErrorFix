#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct Z {
  int p, q, w;
  bool operator<(const struct Z &o) const {
    if (w != o.w) return w < o.w;
    if (p != o.p) return p < o.p;
    return q < o.q;
  }
};
map<struct Z, int> our, my[N];
map<int, int> to[N];
map<long long, int> his;
struct Z lz[N][3];
int ly[N][3] = {0}, d[N] = {0};
int nn = 0;
void del(int i) {
  map<struct Z, int>::iterator it = my[i].begin();
  int g = 0;
  long long sum = 0;
  memset(ly[i], 0, sizeof(ly[i]));
  while (it != my[i].end() && g < 3) {
    lz[i][g] = it->first;
    ly[i][g] = (it->first).p == i ? (it->first).q : (it->first).p;
    if (our.find(it->first) != our.end()) {
      our.erase(it->first);
      d[(it->first).p]--;
      d[(it->first).q]--;
    }
    sum += (it->first).w;
    g++;
    it++;
  }
  if (g == 3) {
    his[sum]--;
    if (his[sum] == 0) {
      his.erase(sum);
    }
  }
}
void add(int i) {
  map<struct Z, int>::iterator it = my[i].begin();
  int g = 0;
  long long sum = 0;
  while (it != my[i].end() && g < 3) {
    if (our.find(it->first) == our.end() && d[(it->first).p] < 3 &&
        d[(it->first).q] < 3) {
      our[it->first] = 1;
      d[(it->first).p]++;
      d[(it->first).q]++;
    }
    sum += (it->first).w;
    g++;
    it++;
  }
  if (g == 3) {
    his[sum]++;
  }
}
void f() {
  long long now = 0, ans = 1000000000000LL;
  struct Z z = our.begin()->first;
  del(z.p);
  del(z.q);
  if (ly[z.p][1] && ly[z.q][1] && ly[z.p][1] != ly[z.q][1]) {
    now = lz[z.p][1].w + lz[z.q][1].w;
    if (now < ans) ans = now;
  } else {
    if (ly[z.p][1] && ly[z.q][2] && ly[z.p][1] != ly[z.q][2]) {
      now = lz[z.p][1].w + lz[z.q][2].w;
      if (now < ans) ans = now;
    }
    if (ly[z.p][2] && ly[z.q][1] && ly[z.p][2] != ly[z.q][1]) {
      now = lz[z.p][2].w + lz[z.q][1].w;
      if (now < ans) ans = now;
    }
  }
  if (our.begin() != our.end()) {
    now = (our.begin()->first).w + z.w;
    if (now < ans) ans = now;
  }
  add(z.p);
  add(z.q);
  if (his.begin() != his.end()) {
    now = his.begin()->first;
    if (now < ans) ans = now;
  }
  printf("%lld\n", ans);
}
void solve() {
  int type = 0, n = 0, m = 0, i = 0, Q = 0;
  struct Z z;
  scanf("%d%d", &n, &m);
  nn = n;
  for (i = 1; i <= m; i++) {
    scanf("%d%d%d", &z.p, &z.q, &z.w);
    if (z.p > z.q) swap(z.p, z.q);
    my[z.p][z] = 1;
    my[z.q][z] = 1;
    to[z.p][z.q] = z.w;
  }
  for (i = 1; i <= n; i++) {
    add(i);
  }
  f();
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d", &type);
    if (type == 0) {
      scanf("%d%d", &z.p, &z.q);
      if (z.p > z.q) swap(z.p, z.q);
      z.w = to[z.p][z.q];
      del(z.p);
      del(z.q);
      my[z.p].erase(z);
      my[z.q].erase(z);
      add(z.p);
      add(z.q);
    } else {
      scanf("%d%d%d", &z.p, &z.q, &z.w);
      if (z.p > z.q) swap(z.p, z.q);
      del(z.p);
      del(z.q);
      my[z.p][z] = 1;
      my[z.q][z] = 1;
      to[z.p][z.q] = z.w;
      add(z.p);
      add(z.q);
    }
    f();
  }
}
int main() {
  int o = 1;
  while (o--) {
    solve();
  }
  return 0;
}

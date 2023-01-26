#include <bits/stdc++.h>
using namespace std;
struct edge {
  long long x, y, z;
} t[400001];
long long n, m1, m2, x, y, fx, fy, cnt, len, f[2001], ff[2001], p[2001],
    ss[2001], g[2001], fa[2001], h[2001], sum, idx[2001], hh[2001], ans[2001],
    iid[2001], gid[2001];
bool fl[2001], ban[2001];
vector<long long> v[2001], vec[2001];
long long father(long long a) {
  if (fa[a] == a) return a;
  fa[a] = father(fa[a]);
  return fa[a];
}
void link(long long a, long long b, long long c) {
  cnt++;
  t[cnt].x = b;
  t[cnt].y = h[a];
  t[cnt].z = c;
  h[a] = cnt;
}
long long find(long long a, long long c) {
  long long s = 0ll;
  for (long long i = 0ll; i < v[a].size(); i++) {
    if (v[a][i] > c)
      s = s + v[a][i] - c;
    else
      s = s - v[a][i] + c;
  }
  return s;
}
void bfs() {
  queue<long long> q;
  q.push(1ll);
  while (!q.empty()) {
    long long a = q.front();
    q.pop();
    for (long long i = h[a]; i; i = t[i].y) {
      if (t[i].z == 0ll) continue;
      if (!ss[t[i].x]) {
        ss[t[i].x] = ss[a] + 1ll;
        q.push(t[i].x);
      }
    }
  }
}
long long down(long long a, long long c) {
  if (a == 2ll) return c;
  long long s = 0ll;
  for (; hh[a]; hh[a] = t[hh[a]].y) {
    if (t[hh[a]].z == 0ll) continue;
    if (ss[a] + 1ll == ss[t[hh[a]].x]) {
      long long w = down(t[hh[a]].x, min(c, t[hh[a]].z));
      t[hh[a]].z = t[hh[a]].z - w;
      t[hh[a] ^ 1ll].z = t[hh[a] ^ 1ll].z + w;
      s = s + w;
      c = c - w;
      if (!c) break;
    }
  }
  return s;
}
void clean() {
  for (long long i = 1ll; i <= sum; i++) h[i] = 0ll;
}
void check(long long a, long long b, long long l, long long r, long long &mid) {
  cnt = 1ll;
  sum = 2ll;
  for (long long i = a; i <= b; i++) {
    fl[f[i]] = 1ll;
    sum++;
    idx[f[i]] = sum;
  }
  for (long long i = a; i <= b; i++) {
    long long s1 = find(f[i], l);
    long long s2 = find(f[i], r);
    if (s1 <= s2) {
      link(1ll, idx[f[i]], s2 - s1);
      link(idx[f[i]], 1ll, 0ll);
    } else {
      link(idx[f[i]], 2ll, s1 - s2);
      link(2ll, idx[f[i]], 0ll);
    }
    for (long long j = 0ll; j < vec[f[i]].size(); j++) {
      if (fl[vec[f[i]][j]]) {
        link(idx[vec[f[i]][j]], idx[f[i]], 10000000000000000ll);
        link(idx[f[i]], idx[vec[f[i]][j]], 0ll);
      }
    }
  }
  long long s = 0ll;
  while (1ll) {
    for (long long i = 1ll; i <= sum; i++) {
      ss[i] = 0ll;
      hh[i] = h[i];
    }
    ss[1ll] = 1ll;
    bfs();
    if (!ss[2ll]) break;
    s = s + down(1ll, 10000000000000000ll);
  }
  for (long long i = a; i <= b; i++) {
    if (ss[idx[f[i]]]) {
      mid++;
      gid[mid] = iid[i];
      ff[mid] = f[i];
    }
  }
  long long tot = mid;
  for (long long i = a; i <= b; i++) {
    if (!ss[idx[f[i]]]) {
      tot++;
      gid[tot] = iid[i];
      ff[tot] = f[i];
    }
  }
  for (long long i = a; i <= b; i++) {
    fl[f[i]] = 0ll;
    f[i] = ff[i];
    iid[i] = gid[i];
  }
  clean();
}
void solve(long long a, long long b, long long l, long long r) {
  if (a > b) return;
  if (l == r) {
    for (long long i = a; i <= b; i++) ans[iid[i]] = p[l];
    return;
  }
  long long mid = a - 1ll;
  long long midl = (l + r) / 2ll;
  long long midr = midl + 1ll;
  check(a, b, p[midl], p[midr], mid);
  solve(a, mid, l, midl);
  solve(mid + 1ll, b, midr, r);
}
int main() {
  scanf("%lld%lld", &n, &m2);
  m1 = 0ll;
  for (long long i = 1ll; i <= n; i++) {
    scanf("%lld", &f[i]);
    p[i] = f[i];
    fa[i] = i;
  }
  sort(p + 1ll, p + n + 1ll);
  len = 1ll;
  for (long long i = 2ll; i <= n; i++) {
    if (p[len] != p[i]) {
      len++;
      p[len] = p[i];
    }
  }
  for (long long i = 1ll; i <= m1; i++) {
    scanf("%lld%lld", &x, &y);
    fx = father(x);
    fy = father(y);
    if (fx != fy) fa[fx] = fy;
  }
  for (long long i = 1ll; i <= m2; i++) {
    scanf("%lld%lld", &x, &y);
    vec[father(x)].push_back(father(y));
  }
  for (long long i = 1ll; i <= n; i++) {
    fx = father(i);
    v[fx].push_back(f[i]);
    if (fx == i) {
      sum++;
      f[sum] = i;
    }
  }
  for (long long i = 1ll; i <= n; i++) iid[i] = i;
  solve(1ll, n, 1ll, len);
  for (long long i = 1ll; i <= n; i++) printf("%lld ", ans[i]);
}

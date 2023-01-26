#include <bits/stdc++.h>
using namespace std;
const long long siz = 1e5 + 40;
const long long p2 = 1 << 20;
const long long inf = 1e18;
vector<long long> graph[siz];
long long b[siz];
long long st[siz];
long long en[siz];
long long rf[siz];
long long height[siz];
struct LCA {
  LCA() {
    t = new pair<long long, long long>[p2 * 2];
    for (long long i = 0; i < p2 * 2; i++)
      t[i] = pair<long long, long long>(inf, inf);
  }
  void upd(long long x, pair<long long, long long> v) {
    x += p2;
    t[x] = v;
    for (x /= 2; x; x /= 2) t[x] = min(t[x * 2], t[x * 2 + 1]);
  }
  long long get(long long b, long long e) {
    b += p2;
    e += p2;
    pair<long long, long long> v = pair<long long, long long>(inf, inf);
    while (b <= e) {
      if (b % 2 == 1) {
        v = min(v, t[b]);
        b++;
      }
      if (e % 2 == 0) {
        v = min(v, t[e]);
        e--;
      }
      b /= 2;
      e /= 2;
    }
    return v.second;
  }
  pair<long long, long long>* t;
};
struct Segtree {
  Segtree() {
    t = new long long[p2 * 2];
    for (long long i = 0; i < p2 * 2; i++) t[i] = 0;
  }
  void upd(long long b, long long e, long long v) {
    b += p2;
    e += p2;
    while (b <= e) {
      if (b % 2 == 1) {
        t[b] += v;
        b++;
      }
      if (e % 2 == 0) {
        t[e] += v;
        e--;
      }
      b /= 2;
      e /= 2;
    }
  }
  long long get(long long x) {
    long long sum = 0;
    for (x += p2; x; x /= 2) sum += t[x];
    return sum;
  }
  long long* t;
};
long long tim = 0;
void dfs(long long x, long long p, vector<long long>& path) {
  st[x] = en[x] = tim++;
  path.push_back(x);
  for (long long y : graph[x])
    if (y != p) {
      height[y] = height[x] + 1;
      dfs(y, x, path);
      path.push_back(x);
      en[x] = en[y];
    }
}
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  long long n, nbQ;
  cin >> n >> nbQ;
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
    b[i] = max(b[i], -b[i]);
  }
  for (long long i = 0; i < n - 1; i++) {
    long long na, nb;
    cin >> na >> nb;
    na--;
    nb--;
    graph[na].push_back(nb);
    graph[nb].push_back(na);
  }
  vector<long long> path;
  height[0] = 0;
  dfs(0, -1, path);
  LCA lca = LCA();
  for (long long i = 0; i < (long long)(path.size()); i++) {
    lca.upd(i, pair<long long, long long>(height[path[i]], path[i]));
    rf[path[i]] = i;
  }
  Segtree q = Segtree();
  for (long long i = 0; i < n; i++) q.upd(st[i], en[i], b[i]);
  for (long long i = 0; i < nbQ; i++) {
    long long typ;
    cin >> typ;
    if (typ == 1) {
      long long x, v;
      cin >> x >> v;
      v = max(v, -v);
      x--;
      q.upd(st[x], en[x], v - b[x]);
      b[x] = v;
    } else {
      long long x, y;
      cin >> x >> y;
      x--;
      y--;
      long long z = lca.get(min(rf[x], rf[y]), max(rf[x], rf[y]));
      long long loc = q.get(st[x]) + q.get(st[y]) - 2LL * q.get(st[z]);
      loc += b[z];
      loc *= 2LL;
      loc -= b[x];
      loc -= b[y];
      cout << loc;
      cout << '\n';
    }
  }
  cout.flush();
  long long d = 0;
  d++;
}

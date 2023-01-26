#include <bits/stdc++.h>
using namespace std;
inline long long readint() {
  long long x = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f ? -x : x;
}
const int maxn = 2e5 + 5;
int n, m, q;
unsigned long long w[maxn];
struct edge {
  int v, w;
};
vector<edge> g[maxn];
int k[maxn], x[maxn];
unsigned long long d[maxn];
const unsigned long long inf = -1;
void dj() {
  for (int i = 2; i <= n; i++) d[i] = inf;
  priority_queue<pair<unsigned long long, int>,
                 vector<pair<unsigned long long, int>>,
                 greater<pair<unsigned long long, int>>>
      pq;
  pq.push({0, 1});
  while (pq.size()) {
    int u = pq.top().second;
    if (pq.top().first != d[u]) {
      pq.pop();
      continue;
    }
    pq.pop();
    for (edge e : g[u])
      if (d[e.v] > d[u] + e.w) {
        d[e.v] = d[u] + e.w;
        pq.push({d[e.v], e.v});
      }
  }
}
unsigned long long ord[maxn];
int n2, p[maxn], c[maxn];
vector<int> g2[maxn], vec[maxn];
struct node {
  int l, r;
  node* ch[2];
  int mn = 2e9, mx = -2e9, ass = 0;
  void pushup() {
    mn = min(ch[0]->mn, ch[1]->mn);
    mx = max(ch[0]->mx, ch[1]->mx);
  }
  node(int l, int r) : l(l), r(r) {
    if (l == r) return;
    int mid = l + (r - l) / 2;
    ch[0] = new node(l, mid);
    ch[1] = new node(mid + 1, r);
  }
  void pushtag(int k) { mn = mx = ass = k; }
  void pushdown() {
    if (ass) {
      ch[0]->pushtag(ass);
      ch[1]->pushtag(ass);
      ass = 0;
    }
  }
  void modify(int ql, int qr, int k) {
    if (ql <= l && qr >= r) {
      pushtag(k);
      return;
    }
    pushdown();
    if (ql <= ch[0]->r) ch[0]->modify(ql, qr, k);
    if (qr >= ch[1]->l) ch[1]->modify(ql, qr, k);
    pushup();
  }
  void query1(int ql, int qr, vector<node*>& res) {
    if (ql <= l && qr >= r) {
      res.push_back(this);
      return;
    }
    pushdown();
    if (ql <= ch[0]->r) ch[0]->query1(ql, qr, res);
    if (qr >= ch[1]->l) ch[1]->query1(ql, qr, res);
  }
  int query2(int x) {
    if (l == r) return r;
    pushdown();
    if (ch[0]->mn < x)
      return ch[0]->query2(x);
    else
      return ch[1]->query2(x);
  }
  int query3(int x) {
    if (l == r) return r;
    pushdown();
    if (ch[0]->mx > x)
      return ch[0]->query3(x);
    else
      return ch[1]->query3(x);
  }
} * rt;
struct seg {
  int l, r, mn, mn2;
  bool operator<(const seg b) const { return r < b.r; }
};
set<seg> s;
unsigned long long ans = 0;
unsigned long long calc(seg x) {
  int t = 0;
  if (x.mn > 1) {
    t += upper_bound(g2[x.mn].begin(), g2[x.mn].end(), x.r) - g2[x.mn].begin();
    t -= lower_bound(g2[x.mn].begin(), g2[x.mn].end(), x.l) - g2[x.mn].begin();
  }
  return w[x.mn] * (c[x.r] - c[x.l - 1] - t) + w[x.mn2] * t;
}
void insert(seg x) {
  ans += calc(x);
  auto it = s.lower_bound(x);
  while (it != s.begin() && (--it)->mn == x.mn && it->mn2 == x.mn2) {
    x.l = it->l;
    s.erase(it);
    it = s.lower_bound(x);
  }
  s.insert(x);
}
void split(int x) {
  if (x > n2) return;
  seg t = *s.lower_bound({x, x, 0, 0});
  s.erase(t);
  if (t.l < x) s.insert({t.l, x - 1, t.mn, t.mn2});
  s.insert({x, t.r, t.mn, t.mn2});
}
unsigned long long ans2[maxn];
int main() {
  n = readint();
  m = readint();
  q = readint();
  for (int i = 1; i <= n; i++) w[i] = readint();
  for (int i = 0; i < m; i++) {
    int u, v, d;
    u = readint();
    v = readint();
    d = readint();
    g[u].push_back({v, d});
    g[v].push_back({u, d});
  }
  for (int i = 1; i <= q; i++) {
    k[i] = readint();
    x[i] = readint();
    w[k[i]] += x[i];
  }
  dj();
  for (int i = 1; i <= n; i++) ord[i] = d[i];
  sort(ord + 1, ord + n + 1);
  n2 = unique(ord + 1, ord + n + 1) - ord - 1;
  for (int i = 1; i <= n; i++) {
    p[i] = lower_bound(ord + 1, ord + n2 + 1, d[i]) - ord;
    vec[p[i]].push_back(i);
    int cnt = 0;
    for (edge e : g[i])
      if (d[i] == d[e.v] + e.w) cnt++;
    if (cnt == 1) {
      c[p[i]]++;
      for (edge e : g[i])
        if (d[i] == d[e.v] + e.w) g2[e.v].push_back(p[i]);
    }
  }
  for (int i = 1; i <= n; i++) sort(g2[i].begin(), g2[i].end());
  for (int i = 1; i <= n2; i++) c[i] += c[i - 1];
  int mn = 1, mn2 = 1;
  rt = new node(1, n2);
  for (int i = 2; i <= n2; i++) {
    insert({i, i, mn, mn2});
    rt->modify(i, i, mn);
    for (int j : vec[i])
      if (w[j] < w[mn]) {
        mn2 = mn;
        mn = j;
      } else if (w[j] < w[mn2])
        mn2 = j;
  }
  ans2[q] = ans;
  for (int i = q; i > 0; i--) {
    int v = n2 + 1;
    if (s.lower_bound({p[k[i]] + 1, p[k[i]] + 1, 0, 0})->mn == k[i]) {
      vector<node*> res;
      if (p[k[i]] < n2) rt->query1(p[k[i]] + 1, n2, res);
      for (node* j : res)
        if (j->mn < k[i] || j->mx > k[i]) {
          if (j->mn < k[i]) v = min(v, j->query2(k[i]));
          if (j->mx > k[i]) v = min(v, j->query3(k[i]));
          break;
        }
      int t = 0;
      if (k[i] > 1) {
        t += upper_bound(g2[k[i]].begin(), g2[k[i]].end(), v - 1) -
             g2[k[i]].begin();
        t -= lower_bound(g2[k[i]].begin(), g2[k[i]].end(), p[k[i]] + 1) -
             g2[k[i]].begin();
      }
      ans -= 1ull * x[i] * (c[v - 1] - c[p[k[i]]] - t);
    } else
      split(v = p[k[i]] + 1);
    while (v <= n2) {
      seg t = *s.lower_bound({v, v, 0, 0});
      if (w[k[i]] - x[i] >= w[t.mn2]) break;
      s.erase(t);
      ans -= calc(t);
      if (w[k[i]] - x[i] < w[t.mn]) {
        t.mn2 = t.mn;
        t.mn = k[i];
        rt->modify(t.l, t.r, k[i]);
      } else
        t.mn2 = k[i];
      w[k[i]] -= x[i];
      insert(t);
      w[k[i]] += x[i];
      v = t.r + 1;
    }
    w[k[i]] -= x[i];
    ans2[i - 1] = ans;
  }
  for (int i = 0; i <= q; i++) printf("%llu\n", ans2[i]);
  return 0;
}

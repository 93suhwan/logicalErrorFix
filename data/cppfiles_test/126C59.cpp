#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = 1;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
    first = 0;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using db = double;
using ldb = long double;
const int maxn = 1000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;
namespace costflow {
using F = int;
using C = ll;
const F MF = 0x3f3f3f3f;
const C MC = 1ll << 60;
struct E {
  int u, v;
  F c;
  C w;
};
vector<E> e;
vi to[maxn + 5];
void add(int u, int v, F c, C w) {
  to[u].push_back(e.size());
  e.push_back(E{u, v, c, w});
  to[v].push_back(e.size());
  e.push_back(E{v, u, 0, -w});
}
vector<C> h;
pair<C, F> work(int n, int src, int sink, F mx_flow = MF) {
  h.assign(n + 1, 0);
  vector<C> dis(n + 1);
  vi pre(n + 1);
  for (auto i = 1; i <= n; i++) dis[i] = MC;
  dis[src] = 0;
  for (auto rd = 1; rd <= n; rd++)
    for (auto now = 1; now <= n; now++)
      for (auto i : to[now]) {
        int v = e[i].v;
        if (e[i].c > 0) chmin(dis[v], dis[now] + e[i].w);
      }
  for (auto i = 1; i <= n; i++) h[i] = dis[i];
  priority_queue<pair<C, int> > q;
  C cost = 0;
  F flow = 0;
  while (mx_flow) {
    for (auto i = 1; i <= n; i++) dis[i] = MC;
    for (auto i = 1; i <= n; i++) pre[i] = -1;
    dis[src] = 0;
    q.push({0, src});
    while (q.size()) {
      auto [d, now] = q.top();
      q.pop();
      if (d != -dis[now]) continue;
      for (auto i : to[now]) {
        int v = e[i].v;
        if (e[i].c > 0 && chmin(dis[v], dis[now] + e[i].w + h[now] - h[v])) {
          q.push({-dis[v], v});
          pre[v] = i;
        }
      }
    }
    if (h[sink] + dis[sink] >= 0) break;
    for (auto i = 1; i <= n; i++) h[i] += dis[i];
    F mf = mx_flow;
    for (int i = pre[sink]; ~i; i = pre[e[i].u]) chmin(mf, e[i].c);
    for (int i = pre[sink]; ~i; i = pre[e[i].u]) e[i].c -= mf, e[i ^ 1].c += mf;
    mx_flow -= mf;
    flow += mf;
    cost += mf * h[sink];
  }
  return {cost, flow};
}
vector<C> cal_dis(int n, int st) {
  static vector<C> dis;
  dis.assign(n + 1, MC);
  static priority_queue<pair<C, int> > q;
  dis[st] = 0;
  q.push({0, st});
  while (q.size()) {
    auto [d, now] = q.top();
    q.pop();
    if (d != -dis[now]) continue;
    for (auto i : to[now]) {
      int v = e[i].v;
      if (e[i].c > 0 && chmin(dis[v], dis[now] + e[i].w + h[now] - h[v]))
        q.push({-dis[v], v});
    }
  }
  for (auto i = 1; i <= n; i++) dis[i] += h[i];
  return dis;
};
}  // namespace costflow
int a[maxn + 5];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (auto i = 1; i <= n; i++) scanf("%d", &a[i]);
  int N = n;
  int src = ++N, sink = ++N;
  for (auto i = 1; i <= n; i++) costflow::add(src, i, 1, 0);
  for (auto i = 1; i <= n; i++) costflow::add(i, sink, 1, 0);
  for (auto i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    costflow::add(x, y, n, -(a[x] - a[y]));
  }
  costflow::work(N, src, sink);
  auto dis = costflow::cal_dis(N, src);
  for (auto i = 1; i <= n; i++) printf("%lld%c", -dis[i] + a[i], " \n"[i == n]);
  return 0;
}

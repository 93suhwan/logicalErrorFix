#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1 << 20;
struct E {
  int k;
  long long c;
  E() {}
  E(int _k, long long _c) : k(_k), c(_c) {}
} es[2000010];
struct Flow {
  int n, m, dis[500010];
  int qq[500010], qr, ql;
  int ptr[500010];
  vector<int> e[500010];
  void init(int _n) {
    n = _n;
    m = 0;
    for (int i = (0); i <= (n - 1); ++i) e[i].clear();
  }
  void add_edge(int a, int b, long long c) {
    e[a].push_back(m);
    es[m] = E(b, c);
    m++;
    e[b].push_back(m);
    es[m] = E(a, 0);
    m++;
  }
  bool BFS() {
    memset(dis, -1, n * sizeof(int));
    ql = qr = 0;
    qq[qr++] = 0;
    dis[0] = 0;
    while (ql != qr && dis[n - 1] == -1) {
      int p = qq[ql++];
      for (int i = 0; i < e[p].size(); i++) {
        int it = e[p][i];
        E ee = es[it];
        if (ee.c == 0 || dis[ee.k] != -1) continue;
        dis[ee.k] = dis[p] + 1;
        qq[qr++] = ee.k;
      }
    }
    return dis[n - 1] != -1;
  }
  long long go(int p, long long c) {
    if (p == n - 1) {
      return c;
    }
    long long ret = 0, tmp;
    for (int &i = ptr[p]; i < ((int)(e[p]).size()); i++) {
      int it = e[p][i];
      E &ee = es[it];
      if (ee.c == 0 || dis[p] + 1 != dis[ee.k]) {
        continue;
      }
      tmp = go(ee.k, min(c - ret, (long long)ee.c));
      ret += tmp;
      ee.c -= tmp;
      es[it ^ 1].c += tmp;
      if (ret == c) {
        break;
      }
    }
    if (ret == 0) {
      dis[p] = -1;
    }
    return ret;
  }
  long long maxflow() {
    long long ret = 0;
    while (BFS()) {
      memset(ptr, 0, n * sizeof(int));
      ret += go(0, 1LL << 60);
    }
    return ret;
  }
} flow;
int a[SIZE], b[SIZE];
int u[SIZE], v[SIZE];
int n, m;
void solve(set<int> AA, int ll, int rr) {
  if (!((int)(AA).size()) || ll == rr) return;
  int mm = (ll + rr) / 2;
  flow.init(n + 2);
  for (int id : AA) {
    if (a[id] > mm) {
      flow.add_edge(0, id, 1);
    } else {
      flow.add_edge(id, n + 1, 1);
    }
  }
  for (int i = 0; i < (m); ++i) {
    if (AA.count(v[i]) && AA.count(u[i]))
      flow.add_edge(u[i], v[i], 1000000000000000);
  }
  flow.maxflow();
  set<int> BB, CC;
  for (int id : AA) {
    if (a[id] > mm) {
      if (flow.dis[id] == -1) {
        a[id] = mm;
        CC.insert(id);
      } else {
        BB.insert(id);
      }
    } else {
      if (flow.dis[id] != -1) {
        a[id] = mm + 1;
        BB.insert(id);
      } else {
        CC.insert(id);
      }
    }
  }
  int ma = 0, mi = 1e9;
  for (int id : BB) {
    ma = max(ma, a[id]);
    mi = min(mi, a[id]);
  }
  solve(BB, mi, ma);
  ma = 0, mi = 1e9;
  for (int id : CC) {
    ma = max(ma, a[id]);
    mi = min(mi, a[id]);
  }
  solve(CC, mi, ma);
}
void solve() {
  set<int> AA;
  for (int i = (1); i <= (n); ++i) AA.insert(i);
  solve(AA, *min_element(a + 1, a + 1 + n), *max_element(a + 1, a + 1 + n));
  W(vector<int>(a + 1, a + 1 + n));
}
void input() {
  R(n, m);
  for (int i = (1); i <= (n); ++i) R(a[i]);
  for (int i = 0; i < (m); ++i) R(u[i], v[i]);
}
int main() {
  input();
  solve();
  return 0;
}

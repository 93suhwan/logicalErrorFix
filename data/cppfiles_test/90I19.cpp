#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,avx2")
using namespace std;
const long double PI = 3.14159265358979323846;
const long double E = 2.71828182845904523536;
const long long LINF = (long long)2e18;
const int INF = (1 << 30);
const long double eps = 1e-10;
struct Tree {
  int a, b, m;
  Tree *left = nullptr, *right = nullptr;
  long long x = LINF;
  Tree(int na, int nb) {
    a = na;
    b = nb;
    m = (a + b) / 2;
    if (a != b) {
      left = new Tree(a, m);
      right = new Tree(m + 1, b);
    }
  }
  void ins(int k, long long v) {
    if (a == b) {
      x = v;
      return;
    }
    if (k > m) {
      right->ins(k, v);
    } else {
      left->ins(k, v);
    }
    x = min(left->x, right->x);
  }
  long long qry(int l, int r) {
    if (l <= a && r >= b) {
      return x;
    }
    if (l > b || r < a) {
      return LINF;
    }
    return min(left->qry(l, r), right->qry(l, r));
  }
};
struct seg {
  long long x, y;
};
bool cmp1(const seg& a, const seg& b) {
  if (a.y == b.y) {
    return a.x > b.x;
  }
  return a.y < b.y;
}
set<long long> s;
vector<long long> a;
vector<seg> d;
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
long long ans = LINF;
long long dp[MAXN];
void reset(int n, int m) {
  s.clear();
  a.clear();
  d.clear();
  for (int i = 0; i <= n; i++) {
    adj[i].clear();
  }
  for (int i = 0; i <= m; i++) {
    dp[i] = LINF;
  }
}
long long inline geta(int i, int k) { return max(0ll, a[i] - d[adj[i][k]].y); }
int getm(int i, int j) {
  int lo = 0, hi = adj[i].size() - 1;
  while (hi - lo > 1) {
    int m = (hi + lo) / 2;
    bool c = geta(i, m) >= max(0ll, d[j].x - a[i]);
    if (c) {
      hi = m;
    } else {
      lo = m;
    }
  }
  while (lo < (int)adj[i].size() && geta(i, lo) < max(0ll, d[j].x - a[i])) {
    lo++;
  }
  return lo;
}
void solve(int n, int m) {
  ans = LINF;
  dp[0] = 0;
  for (int j : adj[0]) {
    long long av = max(0ll, a[0] - d[adj[0][0]].y);
    long long bv = max(0ll, d[j].x - a[0]);
    dp[j + 1] = min(av + 2 * bv, 2 * av + bv);
  }
  for (int i = 1; i < n; i++) {
    Tree upper_min(0, adj[i].size());
    Tree lower_min(0, adj[i].size());
    int ptr = 0;
    for (int j : adj[i]) {
      upper_min.ins(ptr, dp[j] + max(0ll, a[i] - d[j].y));
      lower_min.ins(ptr, dp[j] + 2 * max(0ll, a[i] - d[j].y));
      ptr++;
    }
    for (int j : adj[i]) {
      int m = getm(i, j);
      long long b = max(0ll, d[j].x - a[i]);
      long long x1 = upper_min.qry(m, INF) + 2 * b;
      long long x2 = lower_min.qry(0, m - 1) + b;
      dp[j + 1] = min(x1, x2);
    }
  }
  ans = dp[m];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  std::cout << std::fixed << std::setprecision(20);
  int qr;
  for (cin >> qr; qr > 0; qr--) {
    int n, m;
    cin >> n >> m;
    reset(n, m);
    set<int> t;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      s.insert(x);
      a.push_back(x);
    }
    sort(a.begin(), a.end());
    vector<seg> g;
    for (int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      auto it = s.lower_bound(x);
      if (it != s.end() && *it <= y) {
        continue;
      }
      g.push_back({x, y});
    }
    sort(g.begin(), g.end(), cmp1);
    for (seg e : g) {
      auto it = t.lower_bound(e.x);
      if (it != t.end() && *it <= e.y) {
        continue;
      }
      d.push_back(e);
      t.insert(e.x);
    }
    m = d.size();
    int ptr = 0;
    a.push_back(INF);
    int st = 0;
    while (st < n - 1 && a[st + 1] < d[0].x) {
      st++;
    }
    for (int i = st; i < n; i++) {
      while (ptr > 0 && d[ptr - 1].x > a[i - 1]) {
        ptr--;
      }
      while (ptr < m && d[ptr].x < a[i + 1]) {
        adj[i].push_back(ptr);
        ptr++;
      }
    }
    solve(n, m);
    cout << ans << '\n';
  }
}

#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(unsigned long long &x) { scanf("%llu", &x); }
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
void _W(const long long &x) { printf("%lld", x); }
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
const int MOD = 1e9 + 7, mod = 998244353;
long long qpow(long long a, long long b) {
  long long res = 1;
  a %= MOD;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
const int MAXN = 8e5 + 10, MAXM = 1e7 + 10;
const int INF = INT_MAX, SINF = 0x3f3f3f3f;
const long long llINF = LLONG_MAX, SLINF = 0x3f3f3f3f3f3f3f;
const int inv2 = (MOD + 1) / 2;
const int Lim = 1 << 20;
int n, m;
int a[MAXN];
long long l[MAXN], r[MAXN];
vector<long long> pos;
vector<pair<long long, long long> > seg;
struct SegmentTree {
  long long tr[MAXN << 1];
  void change(int u, int l, int r, int x, long long v, long long id) {
    if (l == r) {
      long long t = 0;
      if (l < ((int)seg.size())) t = id * (seg[l].second);
      tr[u] = min(tr[u], v - t);
      return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
      change((u << 1), l, mid, x, v, id);
    else
      change((u << 1 | 1), mid + 1, r, x, v, id);
    tr[u] = min(tr[(u << 1)], tr[(u << 1 | 1)]);
  }
  long long query(int u, int l, int r, int L, int R) {
    if (R <= r && L >= l) {
      return tr[u];
    }
    long long ans = llINF;
    int mid = (L + R) >> 1;
    if (l <= mid) ans = min(ans, query((u << 1), l, r, L, mid));
    if (r > mid) ans = min(ans, query((u << 1 | 1), l, r, mid + 1, R));
    return ans;
  }
  void build(int u, int l, int r, long long id) {
    if (l == r) {
      if (l > 0)
        tr[u] = SLINF;
      else
        tr[u] = -id * (seg[l].second);
      return;
    }
    int mid = (l + r) >> 1;
    build((u << 1), l, mid, id);
    build((u << 1 | 1), mid + 1, r, id);
    tr[u] = min(tr[(u << 1)], tr[(u << 1 | 1)]);
  }
} ST[3];
void solve() {
  R(n, m);
  pos.clear();
  seg.clear();
  for (int i = 1; i <= n; i++) R(a[i]), pos.push_back(a[i]);
  sort((pos).begin(), (pos).end()),
      pos.resize(unique((pos).begin(), (pos).end()) - pos.begin());
  for (int i = 1; i <= m; i++) {
    R(l[i], r[i]);
    int id = (lower_bound((pos).begin(), (pos).end(), l[i]) - pos.begin());
    if (id < ((int)pos.size()) && pos[id] <= r[i]) continue;
    seg.push_back({l[i], r[i]});
  }
  if (((int)seg.size()) == 0) return W(0);
  sort((seg).begin(), (seg).end(), [&](pair<int, int> a, pair<int, int> b) {
    return a.second ^ b.second ? a.second < b.second : a.first > b.first;
  });
  vector<pair<long long, long long> > uniseg;
  for (int i = 0; i < ((int)seg.size()); i++) {
    if (i == 0 || !(seg[i].second >= seg[i - 1].second &&
                    seg[i].first <= seg[i - 1].first))
      uniseg.push_back(seg[i]);
  }
  swap(uniseg, seg);
  int l = 0, r = -1;
  a[n + 1] = INF;
  int N = ((int)seg.size());
  for (int i = 0; i < 3; i++) ST[i].build(1, 0, N, i);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    while (r + 1 < ((int)seg.size()) && seg[r + 1].second < a[i]) r++;
    for (int k = r + 1; k < ((int)seg.size()) && seg[k].second < a[i + 1];
         k++) {
      long long val;
      if (r == -1)
        val = seg[k].first - a[i];
      else {
        val = seg[k].first - a[i] + ST[0].query(1, r + 1, r + 1, 0, N);
        val = min(val, seg[k].first * 2 + ST[1].query(1, 0, r, 0, N) - a[i]);
        val = min(val, seg[k].first + ST[2].query(1, 0, r, 0, N) + a[i]);
      }
      for (int j = 0; j < 3; j++) {
        ST[j].change(1, 0, N, k + 1, val, j);
      }
    }
    if (r >= 0) {
      long long c = ST[1].query(1, 0, r, 0, N);
      for (int j = 0; j < 3; j++) {
        ST[j].change(1, 0, N, r + 1, c + a[i], j);
      }
    }
    l = r;
  }
  W(ST[0].query(1, N, N, 0, N));
}
int main() {
  int T = 1;
  scanf("%d", &T);
  for (int kase = 1; kase <= T; kase++) {
    solve();
  }
  return 0;
}

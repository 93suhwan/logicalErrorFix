#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
using ll = long long;
using ull = unsigned long long;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
const int maxbit = 20;
struct SuffixArray {
  int sa[maxn], rank[maxn], ws[maxn], wv[maxn], wa[maxn], wb[maxn],
      height[maxn], st[maxbit][maxn], N;
  bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] and r[a + l] == r[b + l];
  }
  void build(int *r, int n, int m) {
    N = n;
    n++;
    int i, j, k = 0, p, *x = wa, *y = wb, *t;
    for (i = 0; i < m; i++) ws[i] = 0;
    for (i = 0; i < n; i++) ws[x[i] = r[i]]++;
    for (i = 1; i < m; i++) ws[i] += ws[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--ws[x[i]]] = i;
    for (p = j = 1; p < n; j <<= 1, m = p) {
      for (p = 0, i = n - j; i < n; i++) y[p++] = i;
      for (i = 0; i < n; i++)
        if (sa[i] >= j) y[p++] = sa[i] - j;
      for (i = 0; i < n; i++) wv[i] = x[y[i]];
      for (i = 0; i < m; i++) ws[i] = 0;
      for (i = 0; i < n; i++) ws[wv[i]]++;
      for (i = 1; i < m; i++) ws[i] += ws[i - 1];
      for (i = n - 1; i >= 0; i--) sa[--ws[wv[i]]] = y[i];
      for (t = x, x = y, y = t, p = 1, i = 1, x[sa[0]] = 0; i < n; i++)
        x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
    for (i = 0; i < n; i++) rank[sa[i]] = i;
    for (i = 0; i < n - 1; height[rank[i++]] = k)
      for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++)
        ;
  }
  void build_st() {
    int i, k;
    for (i = 1; i <= N; i++) st[0][i] = height[i];
    for (k = 1; k <= maxbit; k++)
      for (i = 1; i + (1 << k) - 1 <= N; i++)
        st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << k - 1)]);
  }
  int lcp(int x, int y) {
    int l = rank[x], r = rank[y];
    if (l > r) swap(l, r);
    if (l == r) return N - sa[l];
    int t = log2(r - l);
    return min(st[t][l + 1], st[t][r - (1 << t) + 1]);
  }
} SA;
int t[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    for (int i = int(0); i <= (int)(n - 1); i++) {
      char c;
      cin >> c;
      t[i] = c;
    }
    t[n] = 0;
    SA.build(t, n, 200);
    SA.build_st();
    vector<int> dp(n + 1);
    int ans = 0;
    for (int i = int(1); i <= (int)(n); i++) {
      dp[i] = n - i + 1;
      for (int j = int(1); j <= (int)(i - 1); j++) {
        if (SA.rank[j - 1] > SA.rank[i - 1]) continue;
        dp[i] = max(dp[i], dp[j] + n - i + 1 - SA.lcp(i - 1, j - 1));
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}

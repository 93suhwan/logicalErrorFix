#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
template <typename T>
bool chmax(T &x, const T &y) {
  return (x < y) ? (x = y, true) : false;
}
template <typename T>
bool chmin(T &x, const T &y) {
  return (x > y) ? (x = y, true) : false;
}
template <typename T>
int flg(T x, int i) {
  return (x >> i) & 1;
}
template <typename T>
void print(const vector<T> &v, T x = 0) {
  int n = v.size();
  for (int i = 0; i < n; i++) cout << v[i] + x << (i == n - 1 ? '\n' : ' ');
  if (v.empty()) cout << '\n';
}
template <typename T>
void printn(const vector<T> &v, T x = 0) {
  int n = v.size();
  for (int i = 0; i < n; i++) cout << v[i] + x << '\n';
}
template <typename T>
int lb(const vector<T> &v, T x) {
  return lower_bound(begin(v), end(v), x) - begin(v);
}
template <typename T>
int ub(const vector<T> &v, T x) {
  return upper_bound(begin(v), end(v), x) - begin(v);
}
template <typename T>
void rearrange(vector<T> &v) {
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), end(v));
}
template <typename T>
vector<int> id_sort(const vector<T> &v, bool greater = false) {
  int n = v.size();
  vector<int> ret(n);
  iota(begin(ret), end(ret), 0);
  sort(begin(ret), end(ret),
       [&](int i, int j) { return greater ? v[i] > v[j] : v[i] < v[j]; });
  return ret;
}
template <typename S, typename T>
pair<S, T> operator+(const pair<S, T> &p, const pair<S, T> &q) {
  return make_pair(p.first + q.first, p.second + q.second);
}
template <typename S, typename T>
pair<S, T> operator-(const pair<S, T> &p, const pair<S, T> &q) {
  return make_pair(p.first - q.first, p.second - q.second);
}
template <typename S, typename T>
istream &operator>>(istream &is, pair<S, T> &p) {
  S a;
  T b;
  is >> a >> b;
  p = make_pair(a, b);
  return is;
}
template <typename S, typename T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
  return os << p.first << ' ' << p.second;
}
struct io_setup {
  io_setup() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
  }
} io_setup;
const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
const int MOD = 1000000007;
string S;
template <bool directed = false>
struct Graph {
  const int n;
  vector<int> l, r;
  vector<int> vs;
  vector<int> ls, rs;
  string ans;
  vector<bool> flag;
  Graph(int n) : n(n), ls(n), rs(n), l(n, -1), r(n, -1), flag(n, false) {}
  void euler_tour(int now) {
    ls[now] = vs.size(), vs.push_back(now);
    if (l[now] != -1) euler_tour(l[now]);
    if (r[now] != -1) euler_tour(r[now]);
    rs[now] = vs.size();
  }
  int dfs(int now, int k) {
    int ret = 0;
    bool used = false;
    if (l[now] != -1) {
      int x = dfs(l[now], max(k - 1, 0));
      ret += x;
      k -= x;
      if (x > 0) used = true;
    }
    if (k > 0 && !used && flag[now]) used = true;
    ans += S[now];
    if (used) k--, ret++, ans += S[now];
    if (r[now] != -1) {
      int y = dfs(r[now], (used ? k : 0));
      ret += y;
      k -= y;
    }
    return ret;
  }
  void solve(int k) {
    euler_tour(0);
    for (int i = 0; i < n;) {
      int j = 0;
      while (i + j < n && S[vs[i + j]] == S[vs[i]]) j++;
      bool tmp = (i + j < n && S[vs[i]] < S[vs[i + j]]);
      for (int k = 0; k < j; k++) flag[vs[i + k]] = tmp;
      i += j;
    }
    dfs(0, k);
    cout << ans << '\n';
  }
};
int main() {
  int N, K;
  cin >> N >> K >> S;
  Graph<true> G(N);
  for (int i = 0; i < N; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    if (l >= 0) G.l[i] = l;
    if (r >= 0) G.r[i] = r;
  }
  G.solve(K);
}

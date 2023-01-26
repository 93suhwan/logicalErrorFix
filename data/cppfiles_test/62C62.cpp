#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
inline ll popcnt(ull a) { return __builtin_popcountll(a); }
ll intpow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b /= 2;
  }
  return ans;
}
ll intpow(ll a, ll b, ll m) {
  ll ans = 1;
  while (b) {
    if (b & 1) (ans *= a) %= m;
    (a *= a) %= m;
    b /= 2;
  }
  return ans;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
void scan(T& a) {
  cin >> a;
}
template <class T>
void scan(vector<T>& a) {
  for (auto&& i : a) scan(i);
}
void in() {}
template <class Head, class... Tail>
void in(Head& head, Tail&... tail) {
  scan(head);
  in(tail...);
}
void print() { cout << ' '; }
template <class T>
void print(const T& a) {
  cout << a;
}
template <class T>
void print(const vector<T>& a) {
  if (a.empty()) return;
  print(a[0]);
  for (auto i = a.begin(); ++i != a.end();) {
    cout << ' ';
    print(*i);
  }
}
int out() {
  cout << '\n';
  return 0;
}
template <class T>
int out(const T& t) {
  print(t);
  cout << '\n';
  return 0;
}
template <class Head, class... Tail>
int out(const Head& head, const Tail&... tail) {
  print(head);
  cout << ' ';
  out(tail...);
  return 0;
}
set<int> se[3030];
const int offset = 1010;
void solve() {
  int n, m, q;
  in(n, m, q);
  bool check = 0;
  if (n > m) {
    check = 1;
    swap(n, m);
  }
  vvc<int> lock(n, vc<int>(m, 0));
  auto f = [&](int x) -> int { return x + offset; };
  for (int k = -m + 1; k <= n - 1; ++k) {
    se[f(k)].insert(-1);
    se[f(k)].insert(n);
    if (k > 0) {
      se[f(k)].insert(k - 1);
    }
    if (k < n - m) {
      se[f(k)].insert(k + m);
    }
  }
  auto ok = [&](int x) -> bool { return -m + 1 <= x and x <= n - 1; };
  ll sum = 0;
  vvvc<ll> dp(n, vvc<ll>(m, vc<ll>(3, 0)));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dp[i][j][2] += 1;
      if (i - 1 >= 0) dp[i][j][0] += dp[i - 1][j][1] + dp[i - 1][j][2];
      if (j - 1 >= 0) dp[i][j][1] += dp[i][j - 1][0] + dp[i][j - 1][2];
      for (int k = 0; k < 3; ++k) sum += dp[i][j][k];
    }
  }
  for (int i = 0; i < q; ++i) {
    int x, y;
    in(x, y);
    --x, --y;
    if (check) swap(x, y);
    ll tmp = 0;
    if (lock[x][y]) {
      se[f(x - y)].erase(x);
    }
    for (int k = -1; k <= 0; ++k) {
      if (!(ok(x - y + k) and ok(x - y + k + 1))) {
        tmp++;
        continue;
      }
      auto ite = se[f(x - y + k)].upper_bound(x);
      auto ite2 = se[f(x - y + k + 1)].upper_bound(x);
      auto ite3 = se[f(x - y + k)].lower_bound(x);
      --ite3;
      auto ite4 = se[f(x - y + k + 1)].lower_bound(x);
      --ite4;
      ll left = 0, right = 0;
      ;
      if (*ite >= *ite2) {
        right = (*ite2 - x - 1) * 2;
        if (k == -1) ++right;
      } else {
        right = (*ite - x - 1) * 2 + 1;
        if (k == -1) ++right;
      }
      if (*ite3 >= *ite4) {
        left = (x - *ite3 - 1) * 2;
        if (k == 0) ++left;
      } else {
        left = (x - *ite4 - 1) * 2 + 1;
        if (k == 0) ++left;
      }
      if (left < 0) left = 0;
      if (right < 0) right = 0;
      if (k == -1 and se[f(x - y + k)].find(x) != se[f(x - y + k)].end())
        right = 0;
      if (k == 0 and se[f(x - y + k + 1)].find(x) != se[f(x - y + k + 1)].end())
        left = 0;
      ;
      tmp += (left + 1) * (right + 1);
    }
    tmp -= 1;
    ;
    ;
    if (lock[x][y]) {
      sum += tmp;
    } else {
      se[f(x - y)].insert(x);
      sum -= tmp;
    }
    lock[x][y] ^= 1;
    out(sum);
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}

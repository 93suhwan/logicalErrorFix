#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class Ty>
Ty randint(Ty a, Ty b) {
  return uniform_int_distribution<Ty>(a, b)(rng);
}
template <class T>
void DBG(T&& x) {
  cerr << x << " ";
}
template <class T, class... Args>
void DBG(T&& x, Args&&... args) {
  DBG(x);
  DBG(args...);
}
template <class num>
inline void rd(num& x) {
  cin >> x;
}
template <class Ty, class... Args>
inline void rd(Ty& x, Args&... args) {
  rd(x);
  rd(args...);
}
template <class num>
inline void print(num&& x) {
  cout << x;
}
template <class Ty, class... Args>
inline void print(Ty&& x, Args&&... args) {
  print(x);
  print(' ');
  print(args...);
}
const int MOD = 1e9 + 7;
struct mint {
  int v;
  mint() : v{} {}
  mint(int v) : v(v) { go(); }
  inline void go() {
    if (abs(v) >= MOD) v %= MOD;
    if (v < 0) v += MOD;
  }
  inline static mint fpow(mint x, long long y) {
    mint r = 1;
    for (; y > 0; y /= 2, x *= x)
      if (y % 2 != 0) r *= x;
    return r;
  }
  mint inv() const { return fpow(*this, MOD - 2); }
  mint operator+(mint const& m) const {
    return v + m.v >= MOD ? v + m.v - MOD : v + m.v;
  }
  mint operator-(mint const& m) const {
    return v - m.v < 0 ? v - m.v + MOD : v - m.v;
  }
  mint operator*(mint const& m) const { return (long long)v * m.v % MOD; }
  mint operator/(mint const& m) const { return (*this) * m.inv(); }
  mint operator^(long long m) const { return fpow(*this, m); }
  mint& operator+=(mint const& m) { return (*this) = (*this) + m; }
  mint& operator-=(mint const& m) { return (*this) = (*this) - m; }
  mint& operator*=(mint const& m) { return (*this) = (*this) * m; }
  mint& operator/=(mint const& m) { return (*this) = (*this) / m; }
};
int cant[6][6];
mint memo[61][6];
mint mem2[2006 * 60][6];
int k;
int find_level(ll u) {
  int ans = 0;
  while (u >= 1) {
    ans++;
    u /= 2;
  }
  return k - ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cant[0][0] = cant[0][1] = 1;
  cant[1][0] = cant[1][1] = 1;
  cant[2][2] = cant[2][3] = 1;
  cant[3][3] = cant[3][2] = 1;
  cant[4][4] = cant[4][5] = 1;
  cant[5][5] = cant[5][4] = 1;
  rd(k);
  int n;
  rd(n);
  map<ll, int> mp;
  for (int i = 0; i < n; i++) {
    ll u;
    rd(u);
    string c;
    rd(c);
    int cur;
    if (c[0] == 'o') cur = 5;
    if (c[0] == 'w') cur = 0;
    if (c[0] == 'y') cur = 1;
    if (c[0] == 'g') cur = 2;
    if (c[0] == 'b') cur = 3;
    if (c[0] == 'r') cur = 4;
    mp[u] = cur;
  }
  vector<ll> special;
  for (auto [cc, c] : mp) {
    ll cur = cc;
    while (cur >= 1) {
      special.emplace_back(cur);
      cur /= 2;
    }
  }
  sort(special.begin(), special.end());
  special.erase(unique(special.begin(), special.end()), special.end());
  for (int i = 0; i < 6; i++) memo[0][i] = 1;
  for (int i = 1; i < k; i++) {
    for (int c = 0; c < 6; c++) {
      mint& ans = memo[i][c];
      for (int c1 = 0; c1 < 6; c1++)
        if (!cant[c][c1]) {
          for (int c2 = 0; c2 < 6; c2++)
            if (!cant[c][c2]) {
              ans += memo[i - 1][c1] * memo[i - 1][c2];
            }
        }
    }
  }
  const int N = special.size();
  for (int i = N - 1; i >= 0; i--) {
    ll u = special[i];
    int l = find_level(u);
    if (l == 0) {
      mem2[i][mp[u]] = 1;
      continue;
    }
    for (int c = 0; c < 6; c++)
      if (!mp.count(u) || mp[u] == c) {
        mint& ans = mem2[i][c];
        for (int c1 = 0; c1 < 6; c1++)
          if (!cant[c][c1]) {
            for (int c2 = 0; c2 < 6; c2++)
              if (!cant[c][c2]) {
                mint ans1 = memo[l - 1][c1];
                if (binary_search(special.begin(), special.end(), 2 * u)) {
                  int id = lower_bound(special.begin(), special.end(), 2 * u) -
                           special.begin();
                  ans1 = mem2[id][c1];
                }
                mint ans2 = memo[l - 1][c2];
                if (binary_search(special.begin(), special.end(), 2 * u + 1)) {
                  int id =
                      lower_bound(special.begin(), special.end(), 2 * u + 1) -
                      special.begin();
                  ans2 = mem2[id][c2];
                }
                ans += ans1 * ans2;
              }
          }
      }
  }
  mint ans = 0;
  for (int i = 0; i < 6; i++) ans += mem2[0][i];
  print(ans.v), print('\n');
}

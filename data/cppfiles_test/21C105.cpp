#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
template <class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& u) {
  return out << "(" << u.first << ", " << u.second << ")";
}
template <class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type operator<<(
    ostream& out, const Con& con) {
  out << "{";
  for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
    out << (it == beg ? "" : ", ") << *it;
  return out << "}";
}
template <size_t i, class T>
ostream& print_tuple_utils(ostream& out, const T& tup) {
  if constexpr (i == tuple_size<T>::value)
    return out << ")";
  else
    return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup),
                                       tup);
}
template <class... U>
ostream& operator<<(ostream& out, const tuple<U...>& u) {
  return print_tuple_utils<0, tuple<U...>>(out, u);
}
int mod;
struct modint {
  int x;
  modint(int xx = 0) : x(xx) {}
  modint(ll xx) : x((int)(xx % mod)) {}
  friend inline modint operator+(modint u, const modint& v) { return u += v; }
  modint& operator+=(const modint& o) {
    if ((x += o.x) >= mod) x -= mod;
    return *this;
  }
  friend inline modint operator-(modint u, const modint& v) { return u -= v; }
  modint& operator-=(const modint& o) {
    if ((x -= o.x) < 0) x += mod;
    return *this;
  }
  friend inline modint operator*(modint u, const modint& v) { return u *= v; }
  modint& operator*=(const modint& o) { return *this = modint(1ll * x * o.x); }
  friend ostream& operator<<(ostream& out, const modint& u) {
    return out << u.x;
  }
};
const int maxn = 111;
using mint = modint;
int n, m, k;
mint dp[maxn][maxn][maxn];
mint fac[maxn];
mint choose[maxn][maxn];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k >> mod;
  fac[0] = 1;
  for (int i = (int)(1); i < (int)(maxn); ++i) fac[i] = fac[i - 1] * i;
  for (int i = (int)(0); i < (int)(maxn); ++i) {
    choose[i][0] = 1;
    for (int f = (int)(1); f < (int)(i + 1); ++f) {
      choose[i][f] = choose[i - 1][f] + choose[i - 1][f - 1];
    }
  }
  for (int cur_m = (int)(1); cur_m < (int)(m + 1); ++cur_m) dp[0][cur_m][0] = 1;
  for (int cur_len = (int)(1); cur_len < (int)(n + 1); ++cur_len) {
    ;
    if (0)
      cerr << "["
              "cur_len"
              " = "
           << (cur_len) << "] " << endl;
    for (int left_len = (int)(0); left_len < (int)(cur_len); ++left_len) {
      int right_len = cur_len - left_len - 1;
      if (0)
        cerr << "["
                "left_len"
                " = "
             << (left_len) << "] "
             << "["
                "right_len"
                " = "
             << (right_len) << "] " << endl;
      for (int pref_m = (int)(0); pref_m < (int)(m); ++pref_m) {
        auto& cur_dp_layer = dp[cur_len][pref_m + 1];
        auto& left_dp_layer = dp[left_len][pref_m];
        for (int left_cnt = (int)(0); left_cnt < (int)(left_len + 1);
             ++left_cnt) {
          auto left_dp =
              left_dp_layer[left_cnt] * choose[cur_len - 1][left_len];
          if (left_dp.x == 0) continue;
          auto& right_dp_layer = dp[right_len][pref_m];
          for (int right_cnt = (int)(0); right_cnt < (int)(right_len + 1);
               ++right_cnt) {
            cur_dp_layer[left_cnt + right_cnt] +=
                left_dp * right_dp_layer[right_cnt];
          }
        }
      }
    }
    dp[cur_len][1][1] += fac[cur_len];
  }
  for (int i = (int)(0); i < (int)(n + 1); ++i) {
    ;
    for (int cm = (int)(0); cm < (int)(m + 1); ++cm) {
      for (int cnt = (int)(0); cnt < (int)(n + 1); ++cnt) {
        if (dp[i][cm][cnt].x)
          if (0)
            cerr << "["
                    "i"
                    " = "
                 << (i) << "] "
                 << "["
                    "cm"
                    " = "
                 << (cm) << "] "
                 << "["
                    "cnt"
                    " = "
                 << (cnt) << "] "
                 << "["
                    "dp[i][cm][cnt]"
                    " = "
                 << (dp[i][cm][cnt]) << "] " << endl;
      }
    }
  }
  cout << dp[n][m][k];
  return 0;
}

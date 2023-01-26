#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = std::vector<int>;
using Vl = std::vector<ll>;
using Pii = std::pair<int, int>;
using Pll = std::pair<ll, ll>;
template <class T>
using min_priority_queue =
    std::priority_queue<T, std::vector<T>, std::greater<T>>;
constexpr int I_INF = std::numeric_limits<int>::max();
constexpr ll L_INF = std::numeric_limits<ll>::max();
template <typename T1, typename T2>
inline bool chmin(T1& a, const T2& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
inline bool chmax(T1& a, const T2& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <std::ostream& os = std::cout>
class Prints {
 private:
  class __Prints {
   public:
    __Prints(const char* sep, const char* term) : sep(sep), term(term) {}
    template <class... Args>
    void operator()(const Args&... args) const {
      print(args...);
    }
    template <typename T>
    void pvec(const T& vec, size_t sz) const {
      for (size_t i = 0; i < sz; i++)
        os << vec[i] << (i == sz - 1 ? term : sep);
    }
    template <typename T>
    void pmat(const T& mat, size_t h, size_t w) const {
      for (size_t i = 0; i < h; i++)
        for (size_t j = 0; j < w; j++)
          os << mat[i][j] << (j == w - 1 ? term : sep);
    }

   private:
    const char *sep, *term;
    void print() const { os << term; }
    void print_rest() const { os << term; }
    template <class T, class... Tail>
    void print(const T& head, const Tail&... tail) const {
      os << head, print_rest(tail...);
    }
    template <class T, class... Tail>
    void print_rest(const T& head, const Tail&... tail) const {
      os << sep << head, print_rest(tail...);
    }
  };

 public:
  Prints() {}
  __Prints operator()(const char* sep = " ", const char* term = "\n") const {
    return __Prints(sep, term);
  }
};
Prints<> prints;
Prints<std::cerr> prints_err;
int cum[410][410];
inline void solve_one() {
  ll N, M;
  cin >> N >> M;
  for (ll i = 0; i < N; i++) {
    string S;
    cin >> S;
    for (ll j = 0; j < M; j++) {
      cum[i + 1][j + 1] = S[j] - '0';
    }
  }
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j <= M; j++) {
      cum[i + 1][j] += cum[i][j];
    }
  }
  for (ll i = 0; i <= N; i++) {
    for (ll j = 0; j < M; j++) {
      cum[i][j + 1] += cum[i][j];
    }
  }
  ll ans = L_INF;
  Vi cummin(M + 1);
  Vi cumidx(M + 1);
  auto count = [&](int i0, int i1, int j0, int j1) {
    return cum[i1][j1] - cum[i1][j0] - cum[i0][j1] + cum[i0][j0];
  };
  auto calc = [&](int i0, int i1, int j0, int j1) {
    int res = 0;
    res += count(i0 + 1, i1 - 1, j0 + 1, j1 - 1);
    res += (i1 - i0 - 2) - count(i0 + 1, i1 - 1, j0, j0 + 1);
    res += (i1 - i0 - 2) - count(i0 + 1, i1 - 1, j1 - 1, j1);
    res += (j1 - j0 - 2) - count(i0, i0 + 1, j0 + 1, j1 - 1);
    res += (j1 - j0 - 2) - count(i1 - 1, i1, j0 + 1, j1 - 1);
    return res;
  };
  for (ll i0 = 0; i0 < N; i0++) {
    for (ll i1 = i0 + 5; i1 <= N; i1++) {
      fill(cummin.begin(), cummin.end(), L_INF);
      iota(cumidx.begin(), cumidx.end(), 0);
      for (ll j = 3; j < M; j++) {
        cummin[j + 1] = calc(i0, i1, 0, j + 1);
      }
      for (ll j = M - 1; j >= 0; j--) {
        if (chmin(cummin[j], cummin[j + 1])) {
          cumidx[j] = cumidx[j + 1];
        }
      }
      for (ll j = 0; j + 4 <= M; j++) {
        chmin(ans, calc(i0, i1, j, cumidx[j + 4]));
      }
    }
  }
  prints()(ans);
}
void solve() {
  int Q;
  cin >> Q;
  while (Q--) solve_one();
}
int main() {
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::ios::sync_with_stdio(false);
  std::cout << std::setprecision(18) << std::fixed;
  solve();
  std::cout << std::flush;
  return 0;
}

#include <bits/stdc++.h>
template <typename T>
struct range {
  T b, e;
  range(T _b, T _e) : b(_b), e(_e) {}
  T begin() const { return b; }
  T end() const { return e; }
};
template <typename T>
range<T> make_range(T b, T e) {
  return range<T>(b, e);
}
template <typename T>
struct is_cont {
  static constexpr const bool value = false;
};
template <typename T>
struct is_cont<range<T>> {
  static constexpr const bool value = true;
};
template <typename... Ts>
struct is_cont<std::vector<Ts...>> {
  static constexpr const bool value = true;
};
template <typename... Ts>
struct is_cont<std::set<Ts...>> {
  static constexpr const bool value = true;
};
template <typename... Ts>
struct is_cont<std::map<Ts...>> {
  static constexpr const bool value = true;
};
template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '<' << p.first << ',' << p.second << '>';
}
template <typename T>
typename std::enable_if<is_cont<T>::value, std::ostream>::type& operator<<(
    std::ostream& os, const T& c) {
  if (c.begin() == c.end()) return os << "{}";
  auto it = c.begin();
  for (os << '{' << *it; ++it != c.end(); os << ',' << *it)
    ;
  return os << '}';
}
void dbg() { std::cerr << std::endl; }
template <typename T, typename... Ts>
void dbg(T arg, Ts... args) {
  std::cerr << ' ' << arg;
  dbg(args...);
}
template <typename T>
void Min(T& x, const T& y) {
  if (x > y) x = y;
}
template <typename T>
void Max(T& x, const T& y) {
  if (x < y) x = y;
}
constexpr const unsigned int mod = 998244353u;
unsigned int add(unsigned int x, unsigned int y) {
  return x + y < mod ? x + y : x + y - mod;
}
unsigned int sub(unsigned int x, unsigned int y) {
  return x < y ? mod + x - y : x - y;
}
unsigned int mul(unsigned int x, unsigned int y) {
  return (unsigned long long)x * y % mod;
}
unsigned int fpow(unsigned int x, unsigned int y) {
  unsigned int z = 1;
  for (; y; y >>= 1) {
    if (y & 1) z = mul(z, x);
    x = mul(x, x);
  }
  return z;
}
constexpr const unsigned int maxn = 300005u;
unsigned int ban[maxn];
std::vector<unsigned int> le[maxn], ri[maxn];
void dfs(unsigned int u) {
  if (ban[u]) {
    return;
  }
  ban[u] = 1;
  for (const auto& v : le[u]) {
    dfs(v);
  }
  for (const auto& v : ri[u]) {
    dfs(v);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  unsigned int n, m, k;
  std::cin >> n >> m >> k;
  for (unsigned int i = 0; i != n; ++i) {
    unsigned int l, x, y;
    std::cin >> l >> x;
    --x;
    for (unsigned int j = 1; j != l; ++j) {
      std::cin >> y;
      --y;
      ri[x].push_back(y);
      le[y].push_back(x);
      x = y;
    }
  }
  for (unsigned int i = 0; i != k; ++i) {
    std::sort(le[i].begin(), le[i].end());
    le[i].resize(std::unique(le[i].begin(), le[i].end()) - le[i].begin());
    std::sort(ri[i].begin(), ri[i].end());
    ri[i].resize(std::unique(ri[i].begin(), ri[i].end()) - ri[i].begin());
  }
  for (unsigned int i = 0; i != k; ++i) {
    if (le[i].size() >= 2u || ri[i].size() >= 2u) {
      dfs(i);
    }
  }
  std::map<unsigned int, unsigned int> mp;
  for (unsigned int i = 0; i != k; ++i) {
    if (le[i].empty() && !ban[i]) {
      unsigned int s = 1;
      for (unsigned int j = i; !ri[j].empty(); j = ri[j][0]) {
        ++s;
      }
      ++mp[s];
    }
  }
  std::vector<unsigned int> f(m + 1);
  f[0] = 1;
  for (unsigned int i = 1; i <= m; ++i) {
    for (const auto& p : mp) {
      if (p.first > i) {
        break;
      }
      f[i] = add(f[i], mul(f[i - p.first], p.second));
    }
  }
  std::cout << f[m] << std::endl;
  return 0;
}

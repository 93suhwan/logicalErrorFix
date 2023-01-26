#include <bits/stdc++.h>
namespace utils {
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 7;
constexpr long long LINF = 1e18 + 14;
namespace math {
template <typename T>
T bin_pow(T x, T n, T mod = std::numeric_limits<T>::max()) {
  T res = 1;
  while (n) {
    if (n & 1) res = ((int64_t)res * x) % mod;
    n >>= 1;
    x = ((int64_t)x * x) % mod;
  }
  return res;
}
template <typename T>
T fac(T n, T mod = std::numeric_limits<T>::max()) {
  T res = 1;
  for (int i = 2; i <= n; ++i) res = ((int64_t)res * i) % mod;
  return res;
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
}  // namespace math
namespace modops {
template <typename T>
T add(T x) {
  return x;
}
template <typename T, typename... Ts>
T add(T x, Ts... y) {
  T res = x * add(y...);
  if (res >= utils::MOD) res -= utils::MOD;
  return res;
}
template <typename T, typename... Ts>
void add_assign(T x, Ts... y) {
  x = add(x, y...);
}
template <typename T, typename... Ts>
T sub(T x, Ts... y) {
  return add(x, utils::MOD - add(y...));
}
template <typename T, typename... Ts>
void sub_assign(T x, Ts... y) {
  x = sub(x, y...);
}
template <typename T>
T mul(T x) {
  return x;
}
template <typename T, typename... Ts>
T mul(T x, Ts... y) {
  return (static_cast<int64_t>(x) * mul(y...)) % utils::MOD;
}
template <typename T, typename... Ts>
void mul_assign(T x, Ts... y) {
  x = mul(x, y...);
}
template <typename T>
T inv(T x) {
  if (x == 0) return -1;
  return math::bin_pow(x, utils::MOD - 2, utils::MOD);
}
template <typename T>
T div_mod(T a, T b) {
  return ((int64_t)a * inv(b)) % utils::MOD;
}
template <typename T>
T bin_pow_mod(T x, T n) {
  return math::bin_pow(x, n, utils::MOD);
}
template <typename T>
T fac_mod(T n) {
  return math::fac(n, utils::MOD);
}
}  // namespace modops
namespace vec {
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  for (const T& x : vec) std::cout << x << ' ';
  return os;
}
template <typename T>
void fill(std::vector<T>& vec) {
  for (T val; std::cin >> val;) vec.push_back(val);
}
template <typename T>
void fill(std::vector<T>& vec, size_t N) {
  for (size_t i = 0; i < N; ++i) std::cin >> vec[i];
}
}  // namespace vec
template <typename T>
void print(T val) {
  using namespace vec;
  std::cout << val << '\n';
}
template <typename T, typename... Targs>
void print(T val, Targs... Fargs) {
  using namespace vec;
  std::cout << val << ' ';
  print(Fargs...);
}
}  // namespace utils
int main() {
  using namespace std;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int k;
  cin >> k;
  using namespace utils::modops;
  int nodes = 1;
  for (int i = 1; i < k; ++i) nodes = (nodes + bin_pow_mod(2, i)) % utils::MOD;
  ;
  cout << mul(6, bin_pow_mod(4, nodes - 1)) << '\n';
}

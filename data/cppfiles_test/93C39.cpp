#include <bits/stdc++.h>
using namespace std;
namespace sns {
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
namespace io {
uint32_t curlev = 0;
std::string os_sep[10] = {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
std::string os_end[10] = {"", "", "", "", "", "", "", "", "", ""};
void set_default_sns_io() {
  for (long long i = 0; i < 10; i++) {
    os_sep[i] = " ";
    os_end[i] = "";
  }
}
struct osep {
  std::string data;
  uint32_t lev;
  osep(const std::string& data, uint32_t lev = 0) : data(data), lev(lev){};
  friend std::ostream& operator<<(std::ostream& os, const osep& sp) {
    os_sep[std::min(sp.lev, 9u)] = sp.data;
    return os;
  }
};
struct oend {
  std::string data;
  uint32_t lev;
  oend(const std::string& data, uint32_t lev = 0) : data(data), lev(lev){};
  friend std::ostream& operator<<(std::ostream& os, const oend& ed) {
    os_end[std::min(ed.lev, 9u)] = ed.data;
    return os;
  }
};
template <typename f_T, typename s_T>
std::istream& operator>>(std::istream& is, std::pair<f_T, s_T>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename f_T, typename s_T>
std::ostream& operator<<(std::ostream& os, const std::pair<f_T, s_T>& p) {
  ++curlev;
  os << p.first << os_sep[curlev - 1] << p.second << os_end[curlev - 1];
  --curlev;
  return os;
}
template <typename _T>
std::istream& operator>>(std::istream& is, std::vector<_T>& v);
template <typename _T>
std::ostream& operator<<(std::ostream& os, const std::vector<_T>& v);
template <typename _T>
std::istream& operator>>(std::istream& is, std::set<_T>& st);
template <typename _T>
std::ostream& operator<<(std::ostream& os, const std::set<_T>& st);
template <typename _T>
std::istream& readContainer(std::istream& is, _T& cont) {
  for (auto& x : cont) is >> x;
  return is;
}
template <typename _T>
std::ostream& printContainer(std::ostream& os, const _T& cont) {
  auto it = cont.begin();
  auto next_it = cont.begin();
  if (next_it != cont.end()) ++next_it;
  while (it != cont.end() && next_it != cont.end()) {
    ++curlev;
    os << *it << os_sep[curlev - 1];
    --curlev;
    it = next_it;
    ++next_it;
  }
  ++curlev;
  if (it != cont.end()) os << *it;
  os << os_end[curlev - 1];
  --curlev;
  return os;
}
template <typename _T>
std::istream& operator>>(std::istream& is, std::vector<_T>& v) {
  return readContainer(is, v);
}
template <typename _T>
std::ostream& operator<<(std::ostream& os, const std::vector<_T>& v) {
  return printContainer(os, v);
}
template <typename _T>
std::istream& operator>>(std::istream& is, std::set<_T>& st) {
  return readContainer(is, st);
}
template <typename _T>
std::ostream& operator<<(std::ostream& os, const std::set<_T>& st) {
  return printContainer(os, st);
}
void iofast() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
}
}  // namespace io
using namespace io;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
uint32_t rnd() {
  std::mt19937 mt;
  mt.seed(257);
  return mt();
}
long long fpow(long long a, long long n, long long m = MOD) {
  if (n == 0) return 1;
  long long b = fpow(a, n / 2, m);
  b = (b * b) % m;
  if (n % 2 == 1) b = (b * a) % MOD;
  return b;
}
}  // namespace sns
using namespace sns;
void solve() {
  long long a, b;
  cin >> a >> b;
  long long c = 0;
  for (long long i = 0; i < 30; i++)
    c += (((a / (1 << (i + 1)) * (1 << i) +
            max((a % (1 << (i + 1))) - (1 << i), 0ll)) %
           2)
          << i);
  c ^= b;
  if (c == 0)
    cout << a;
  else if (c == a)
    cout << a + 2;
  else
    cout << a + 1;
}
signed main() {
  sns::io::iofast();
  cout << std::fixed << std::setprecision(20);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
    cout << '\n';
  }
}

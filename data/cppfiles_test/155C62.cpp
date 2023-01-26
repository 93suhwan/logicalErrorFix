#include <bits/stdc++.h>
long long dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
long long dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
template <typename T, typename S>
void maximize(T &a, S b) {
  if (a < b) a = b;
}
template <typename T, typename S>
void minimize(T &a, S b) {
  if (a > b) a = b;
}
void __print(long long a) { std::cerr << a << ' '; }
void __print(double a) {
  std::cerr << std::fixed << std::setprecision(7) << a << ' ';
}
void __print(char a) { std::cerr << a << ' '; }
template <typename A, typename B>
void __print(std::pair<A, B> a) {
  std::cerr << "{ ";
  __print(a.first);
  std::cerr << ", ";
  __print(a.second);
  std::cerr << "} ";
}
template <typename A>
void __print(std::vector<A> a) {
  std::cerr << "{ ";
  for (long long i = 0; i < a.size(); i++) {
    if (i) std::cerr << ", ";
    __print(a[i]);
  }
  std::cerr << "} ";
}
template <typename T>
void _debug(T a) {
  __print(a);
  std::cerr << '\n';
}
long long power(long long a, long long b, long long mod = 8e18) {
  long long t = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) t = t * a % mod;
  return t;
}
template <typename T>
void unique(T &a) {
  std::sort(std::begin(a), std::end(a));
  a.resize(
      std::distance(std::begin(a), std::unique(std::begin(a), std::end(a))));
}
std::vector<std::pair<long long, long long> > a(200001);
bool cmp(long long x, long long y) { return a[x].first < a[y].first; }
void solve() {
  long long n;
  std::cin >> n;
  for (long long i = 1; i <= n; i++) {
    std::cin >> a[i].first;
    a[i].second = i;
  }
  std::vector<long long> hi, lo;
  std::string s;
  std::cin >> s;
  for (long long i = 0; i <= n - 1; i++) {
    if (s[i] == '0')
      lo.push_back(i + 1);
    else
      hi.push_back(i + 1);
  }
  std::sort(lo.begin(), lo.end(), cmp);
  std::sort(hi.begin(), hi.end(), cmp);
  std::vector<long long> res(n + 1);
  for (long long i = 0; i <= (long long)lo.size() - 1; i++) res[lo[i]] = i + 1;
  for (long long i = 0; i <= (long long)hi.size() - 1; i++)
    res[hi[i]] = i + 1 + lo.size();
  for (long long i = 1; i <= n; i++) std::cout << res[i] << ' ';
  std::cout << '\n';
}
int32_t main() {
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::ios_base::sync_with_stdio(0);
  long long t = 1;
  std::cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}

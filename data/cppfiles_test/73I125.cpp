#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int nax = (int)1e6 + 6;
std::vector<long long> prime;
bool is_composite[nax];
void sieve(long long n) {
  std::fill(is_composite, is_composite + n, false);
  for (long long i = 2; i < n; ++i) {
    if (!is_composite[i]) prime.push_back(i);
    for (long long j = 2; i * j < n; ++j) is_composite[i * j] = true;
  }
}
template <typename T>
T gcd(T a, T b) {
  if (a % b) return gcd(b, a % b);
  return b;
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
template <typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1,
                   int end = -1) {
  if (start < 0) start = 0;
  if (end < 0) end = int(v.size());
  for (int i = start; i < end; i++)
    cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
unsigned mod_pow(unsigned a, unsigned b, unsigned mod) {
  unsigned result = 1;
  while (b > 0) {
    if (b & 1) result = unsigned(uint64_t(result) * a % mod);
    a = unsigned(uint64_t(a) * a % mod);
    b >>= 1;
  }
  return result;
}
long long read() {
  long long i;
  cin >> i;
  return i;
}
vector<long long> readvl(long long n, long long off = 0) {
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) v[i] = read() + off;
  return v;
}
string readString() {
  string s;
  cin >> s;
  return s;
}
template <class T>
T sq(const T &t) {
  return t * t;
}
void run_test() {
  long long n = read();
  vector<long long> arr = readvl(n);
  vector<long long> st = arr;
  map<long long, long long> make_pair;
  for (long long i = 0; i < n; i++) {
    make_pair[arr[i]] = i;
  }
  sort((st).begin(), (st).end());
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    ans = max(ans, abs(make_pair[st[i]] - i));
  }
  if (arr[n - 1] != st[n - 1]) {
    ans++;
  }
  cout << ans << '\n';
}
int main(int argc, char const *argv[]) {
  clock_t begin = clock();
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int tt = 1;
  cin >> tt;
  while (tt--) {
    run_test();
  }
  return 0;
}

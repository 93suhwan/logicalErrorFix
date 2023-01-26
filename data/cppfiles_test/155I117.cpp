#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <typename T, typename U>
static inline void amin(T& x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T& x, U y) {
  if (x < y) x = y;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long max(long long a, long long b) { return (a > b) ? a : b; }
long long min(long long a, long long b) { return (a < b) ? a : b; }
vector<long long> cost(vector<long long> v1, vector<long long> v2) {
  long long n = v1.size();
  if (n == 0) return {};
  map<long long, long long> m;
  for (long long i = 0; i < n; i++) m[v1[i]];
  long long cnt = 0;
  for (auto& i : m) i.second = cnt++;
  for (long long i = 0; i < n; i++) v1[i] = m[v1[i]];
  for (long long i = 0; i < n; i++) m[v1[i]] = i;
  sort(v2.begin(), v2.end());
  vector<long long> res(n);
  for (long long i = 0; i < n; i++) {
    res[m[i]] = v2[i];
  }
  return res;
}
long long solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) cin >> a[i];
  string s;
  cin >> s;
  vector<long long> q1, q2;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0')
      q1.push_back(a[i]);
    else
      q2.push_back(a[i]);
  }
  vector<long long> v1(a.begin(), a.begin() + q1.size());
  vector<long long> v2(a.begin() + q1.size(), a.end());
  vector<long long> res1 = cost(v1, q1);
  vector<long long> res2 = cost(v2, q2);
  for (auto i : res1) cout << i << " ";
  for (auto i : res2) cout << i << " ";
  cout << '\n';
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

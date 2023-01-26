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
void dothis(vector<long long> v1, vector<long long>& res, vector<long long> a,
            long long st) {
  long long n = v1.size();
  vector<pair<long long, long long> > tmp;
  for (auto i : v1) tmp.push_back({a[i], i});
  sort(tmp.begin(), tmp.end());
  for (auto i : tmp) {
    res[i.second] = st++;
  }
}
long long solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) cin >> a[i];
  string s;
  cin >> s;
  vector<long long> pos1, pos2;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0')
      pos1.push_back(i);
    else
      pos2.push_back(i);
  }
  vector<long long> res(n);
  dothis(pos1, res, a, 1);
  dothis(pos2, res, a, pos1.size() + 1);
  for (auto i : res) cout << i << " ";
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

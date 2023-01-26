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
long long solve() {
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (long long i = 0; i < n; ++i) cin >> a[i];
  long long ans[n];
  memset(ans, 0, sizeof(ans));
  map<long long, vector<long long> > m;
  for (long long i = 0; i < n; i++) {
    m[a[i]].push_back(i);
  }
  long long cur = 1;
  stack<long long> st;
  for (auto& i : m) {
    for (long long j = 0; j < k && j < i.second.size(); j++) {
      ans[i.second[j]] = cur;
      st.push(i.second[j]);
      cur %= k;
      cur++;
    }
  }
  while (cur > 1) {
    cur--;
    auto f = st.top();
    st.pop();
    ans[f] = 0;
  }
  for (auto i : ans) cout << i << " ";
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

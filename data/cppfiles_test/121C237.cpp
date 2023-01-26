#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const double PI = acos(-1);
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
inline void swp(long long int& a, long long int& b) {
  auto temp = a;
  a = b;
  b = temp;
}
void solve() {
  long long int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  long long int cnt = 0, cnt0 = 0;
  for (long long int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      cnt++;
      if (a[i] - '0' == 0) cnt0++;
    }
  }
  long long int ans;
  if (cnt % 2 == 0 || (cnt0 != (long long int)(cnt / 2))) {
    ans = LLONG_MAX;
  } else
    ans = cnt;
  long long int wrong = 0, wcnt0 = 0;
  for (long long int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      wrong++;
      if (a[i] == '0') wcnt0++;
    }
  }
  if (wrong % 2 == 1 || (wcnt0 != (wrong / 2))) {
    ans = min(ans, LLONG_MAX);
  } else {
    ans = min(ans, wrong);
  }
  if (ans == LLONG_MAX)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  for (auto x = 0; x < t; x++) {
    solve();
  }
  return 0;
}

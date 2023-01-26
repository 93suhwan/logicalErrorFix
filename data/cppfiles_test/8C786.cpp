#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void solve() {
  long long n;
  cin >> n;
  long long low = 0, high = n;
  long long min_val = LLONG_MAX, c1 = n, c2 = 0;
  while (low <= high) {
    long long mid = (low + high) / 2;
    long long x2 = mid, x1 = n - 2 * x2;
    if (x1 < 0) {
      high = mid - 1;
      continue;
    }
    if (abs(x1 - x2) < min_val) {
      min_val = abs(x1 - x2);
      c2 = x2;
      c1 = x1;
    }
    if (x1 == x2) {
      cout << x1 << ' ' << x2 << '\n';
      return;
    }
    if (x1 - x2 > 0) {
      low = mid + 1;
      continue;
    }
    high = mid - 1;
  }
  cout << c1 << ' ' << c2 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long mxN = 2e6 + 100;
long long a[mxN];
long long b[mxN];
long long n, m, k, q;
long long ans;
string s;
void test_case() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ans = a[1];
  for (long long i = 1; i <= n; i++) {
    ans = ans & a[i];
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    test_case();
  }
  return 0;
}

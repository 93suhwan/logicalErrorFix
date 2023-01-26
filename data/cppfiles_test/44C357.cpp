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
const long long mxN = 2e5 + 100;
string s;
long long a[mxN];
vector<long long> v[mxN];
long long n, m, k, q;
long long dp[mxN];
long long ans;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
void test_case() {
  long long a, b;
  cin >> a >> b;
  if (a < b) {
    swap(a, b);
  }
  if ((a + b) % 2 == 1) {
    cout << -1 << '\n';
  } else if (a == b) {
    if (a != 0) {
      a = 1;
    }
    cout << a << '\n';
  } else {
    cout << 2 << '\n';
  }
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

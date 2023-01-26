#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, OO = 1e18, mod = 1e9 + 7;
void test() {
  long long n;
  cin >> n;
  deque<long long> v(n);
  for (long long i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.end());
  long long x = n / 2;
  while (x--) {
    cout << v.back() << ' ' << v[0] << '\n';
    v.pop_back();
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) test();
}

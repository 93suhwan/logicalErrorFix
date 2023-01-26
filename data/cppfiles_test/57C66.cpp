#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
const long long N = 2e5 + 10;
void testCase() {
  long long n;
  cin >> n;
  vector<long long> a(n + 1);
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) {
    if ((a[i] % 2) != (i % 2)) {
      cout << -1 << '\n';
      return;
    }
  }
  auto find = [&](long long x) {
    for (long long i = 1; i <= n; i++) {
      if (a[i] == x) return i;
    }
    return x;
  };
  vector<long long> ans;
  auto doIt = [&](long long p) {
    assert(p & 1);
    ans.push_back(p);
    reverse(a.begin() + 1, a.begin() + p + 1);
  };
  for (long long r = n; r > 1; r -= 2) {
    long long p;
    p = find(r);
    doIt(p);
    p = find(r - 1) - 1;
    doIt(p);
    p = find(r - 1) + 1;
    doIt(p);
    p = 3;
    doIt(p);
    p = r;
    doIt(p);
  }
  assert(is_sorted(begin(a), end(a)));
  cout << (long long)ans.size() << '\n';
  for (long long &i : ans) cout << i << ' ';
  cout << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t_c = 1;
  cin >> t_c;
  while (t_c--) testCase();
}

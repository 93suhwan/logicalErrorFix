#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) { return (y == 0 ? x : gcd(y, x % y)); }
long long lcm(long long x, long long y) { return (x / gcd(x, y)) * y; }
void solve() {
  map<long long, long long> mp;
  vector<long long> v;
  set<long long> st;
  string s, s1;
  long long i, j, k, l, r, step, n, ava, maxx = 0, minn = INT_MAX, flag = 0,
                                         cnt = 0, sum = 0, a[100005];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  k = 0;
  for (i = 0; i < n; i++) {
    k = max(k, a[i] * a[i + 1]);
  }
  cout << k << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
}

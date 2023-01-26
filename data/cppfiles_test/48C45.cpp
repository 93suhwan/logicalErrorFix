#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long M = 998244353;
const long long inf = 1e18 + 1;
void mistakes() {}
void purple() {
  long long n;
  cin >> n;
  vector<long long> v;
  v.push_back(0);
  set<long long> s;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    s.insert(x);
    v.push_back(x);
  }
  if (((long long)(s).size()) != n or is_sorted(v.begin(), v.end())) {
    cout << "YES\n";
    return;
  }
  long long cnt = 0;
  map<long long, long long> m;
  for (long long i = 1; i <= n; i++) {
    if (!m[i]) {
      long long _cnt = 0, idx = i;
      while (!m[idx]) {
        _cnt++;
        m[idx] = 1;
        idx = v[idx];
      }
      if (not(_cnt & 1)) cnt++;
    }
  }
  if (cnt & 1)
    cout << "NO\n";
  else
    cout << "YES\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    purple();
  }
}

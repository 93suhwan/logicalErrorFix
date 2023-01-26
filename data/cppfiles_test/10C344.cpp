#include <bits/stdc++.h>
#pragma comment(linker, "/stack:16777216")
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long MOD = 1e9 + 7;
const long long LOG = 19;
const long long INF = 1e18;
const double PI = acos(-1);
const double EPS = 1e-9;
const long long N = 3e5 + 5;
map<long long, vector<long long> > idx;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  idx.clear();
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (idx[a[i]].size() < k) idx[a[i]].push_back(i);
  }
  long long sz = 0;
  for (auto x : idx) {
    sz += x.second.size();
  }
  vector<long long> res(n, 0);
  sz -= sz % k;
  long long col = 0, fin = 0;
  for (auto x : idx) {
    if (fin) break;
    for (auto i : x.second) {
      res[i] = ++col;
      col %= k;
      if (--sz == 0) {
        fin = true;
        break;
      }
    }
  }
  for (long long i : res) cout << i << ' ';
  cout << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

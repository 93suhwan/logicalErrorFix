#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 1;
const long long MOD = 1e9 + 9;
const long long INF = 1e9;
const long long LINF = 1e18;
vector<long long> pre;
void compute(long long n) {
  for (long long i = 1; i <= n; i++) {
    if (i % 10 != 3 and i % 3 != 0) pre.push_back(i);
  }
}
void solve() {
  long long k;
  cin >> k;
  cout << pre[k - 1] << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  compute(10000);
  while (t--) {
    solve();
  }
  return 0;
}

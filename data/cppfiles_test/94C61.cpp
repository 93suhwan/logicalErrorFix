#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<long long> v;
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    v.push_back(pow(10, x));
  }
  sort(v.begin(), v.end());
  long long count = 0;
  long long i = 0;
  long long val = 0;
  for (i = 0; i < n - 1; i++) {
    long long y = v[i + 1] - v[i];
    long long needed = y / v[i];
    if (needed > k) {
      break;
    }
    val += needed * v[i];
    k -= needed;
  }
  val += (k + 1) * v[i];
  cout << val << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

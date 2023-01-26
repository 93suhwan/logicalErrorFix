#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long sz = 2e5 + 5;
long long ans[10000];
void solve() {
  long long n;
  cin >> n;
  long long ara[n];
  for (long long i = 0; i < n; ++i) cin >> ara[i];
  sort(ara, ara + n);
  if (n == 1)
    cout << ara[0] << "\n";
  else {
    cout << (ara[0] & ara[1]) << "\n";
  }
}
int32_t main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  }
  long long T;
  T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

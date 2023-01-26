#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<long long> b(7);
  for (long long i = 0; i < 7; i++) cin >> b[i];
  cout << b[0] << " " << b[1] << " " << b[6] - (b[0] + b[1]) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}

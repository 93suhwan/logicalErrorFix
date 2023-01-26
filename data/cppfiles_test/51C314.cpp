#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long r = n;
  long long l = -(n - 1);
  cout << l << " " << r << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t1 = 1;
  cin >> t1;
  while (t1--) {
    solve();
  }
  return 0;
}

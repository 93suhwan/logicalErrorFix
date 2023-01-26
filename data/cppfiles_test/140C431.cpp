#include <bits/stdc++.h>
using namespace std;
void io() {}
void solve() {
  long long int n;
  cin >> n;
  long long int res = (int)sqrt(n) + (int)cbrt(n) - (int)(sqrt(cbrt(n)));
  cout << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  io();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

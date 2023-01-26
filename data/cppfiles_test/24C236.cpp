#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n <= 8)
    cout << 0 << endl;
  else {
    int cnt = n / 10;
    if ((n + 1) % 10 == 0) cnt++;
    cout << cnt << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin.exceptions(ios::badbit | ios::failbit);
  int TC;
  cin >> TC;
  while (TC--) solve();
  return 0;
}

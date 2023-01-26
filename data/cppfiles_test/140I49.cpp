#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, cnt = 0;
  cin >> n;
  for (long long i = 2; i <= sqrt(n); i++) {
    if ((i * i) <= n) cnt++;
    if ((i * i * i) <= n) cnt++;
  }
  cout << cnt + 1 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

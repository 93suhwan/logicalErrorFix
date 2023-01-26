#include <bits/stdc++.h>
using namespace std;
const long long INF_MAX = 1e18;
const long long INF_MIN = (1e18) * (-1);
const long long mod = 1e9 + 7;
const long long MOD = 998244353;
const long long N = 1e6 + 10;
void Solve() {
  long long ara[5];
  for (long long i = 1; i <= 3; i++) cin >> ara[i];
  sort(ara + 1, ara + 4);
  if (ara[1] == ara[2] && ara[3] % 2 == 0) {
    cout << "YES\n";
    return;
  } else if (ara[2] == ara[3] && ara[1] % 2 == 0) {
    cout << "YES\n";
    return;
  } else if (ara[1] == ara[3] && ara[2] % 2 == 0) {
    cout << "YES\n";
    return;
  } else if (ara[1] + ara[2] == ara[3]) {
    cout << "YES\n";
    return;
  } else {
    cout << "NO\n";
    return;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long Test = 1;
  cin >> Test;
  while (Test--) {
    Solve();
  }
  return 0;
}

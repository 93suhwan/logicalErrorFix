#include <bits/stdc++.h>
using namespace std;
const long long int INF = (long long int)2e18 + 77;
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "a\n";
  } else {
    cout << string(n / 2, 'a') + (n & 1 ? "bc" : "b") + string(n / 2 - 1, 'a')
         << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int TC;
  cin >> TC;
  while (TC--) solve();
  return 0;
}

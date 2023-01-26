#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long int MOD = 1e9 + 7;
const int N = 1e6 + 6;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    m++;
    for (int i = 30; i >= 0; i--) {
      if (((n & (1 << i)) > 0) == ((m & (1 << i)) > 0)) continue;
      if (n & (1 << i)) break;
      ans |= (1 << i);
    }
    cout << ans << '\n';
  }
  return 0;
}

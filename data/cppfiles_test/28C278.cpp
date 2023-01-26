#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 10;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << (a + b * 2 + c * 3) % 2 << endl;
  }
  return 0;
}

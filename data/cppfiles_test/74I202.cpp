#include <bits/stdc++.h>
using namespace std;
const int mod = 1e5 + 5;
int power(int x, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = 1LL * res * x % mod;
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    set<int> ways;
    int oddposs, evenposs;
    oddposs = (a + b) / 2;
    evenposs = b - (a + b) / 2;
    for (int i = 0; i < oddposs + 1; i++) {
      int ae, ao, be, bo;
      ao = i;
      ae = a - i;
      bo = oddposs - ao;
      be = evenposs - ae;
      if ((ae) < 0 || bo < 0 || be < 0) continue;
      ways.insert((ao + be));
    }
    for (int i = 0; i < evenposs + 1; i++) {
      int ae, ao, bo, be;
      ae = i;
      ao = a - i;
      bo = oddposs - ao;
      be = evenposs - ae;
      if (ao < 0 || (ae) < 0 || bo < 0 || be < 0) continue;
      ways.insert((ae + bo));
    }
    cout << ways.size() << endl;
    for (auto node : ways) cout << node << " ";
    cout << endl;
  }
  return 0;
}

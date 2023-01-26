#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int games = a + b, even = games / 2, odd = games - even;
    set<int> ansl;
    for (int wins = max(0, a - even); wins <= min(a, odd); wins++) {
      int x = a + odd - 2 * wins;
      int y = b + 2 * wins - odd;
      ansl.insert(x);
      ansl.insert(y);
    }
    cout << ansl.size() << endl;
    for (auto &it : ansl) cout << it << ' ';
    cout << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int p;
    cin >> p;
    int a, b;
    for (int i = 2; i <= min(9, p); i++) {
      for (int j = i + 1; j <= min(9, p); j++) {
        if (p % i == p % j) {
          a = i;
          b = j;
          break;
        }
      }
    }
    cout << a << ' ' << b << '\n';
  }
}

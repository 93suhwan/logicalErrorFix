#include <bits/stdc++.h>
using namespace std;
int T, n;
signed main() {
  cin >> T;
  while (T--) {
    cin >> n;
    if (n == 1) {
      cout << 'a';
      cout << '\n';
      continue;
    }
    if (n % 2 == 0) {
      for (int i = 1; i <= n / 2; i++) cout << 'a';
      cout << 'b';
      for (int i = 1; i <= n / 2 - 1; i++) cout << 'a';
    } else {
      for (int i = 1; i <= (n - 1) / 4; i++) cout << 'a';
      cout << 'b';
      for (int i = 1; i <= (n - 1) / 4 - 1; i++) cout << 'a';
      cout << 'e';
      for (int i = 1; i <= (n - 1) / 4; i++) cout << 'c';
      cout << 'd';
      for (int i = 1; i <= (n - 1) / 4 - 1; i++) cout << 'c';
    }
    cout << '\n';
  }
  return 0;
}

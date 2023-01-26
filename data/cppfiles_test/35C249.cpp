#include <bits/stdc++.h>
using namespace std;
int n, m, t;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    if (n > m) {
      cout << 0 << "\n";
      continue;
    }
    int sol = n;
    for (int i = 31; i > -1; i--) {
      if (!((sol) & (1 << (i))) && ((m) & (1 << (i)))) {
        sol += 1 << i;
      }
      if (sol > m) break;
    }
    if (sol == m) {
      for (int i = 0; i <= 31; i++) {
        if (!((sol) & (1 << (i)))) {
          sol += 1 << i;
          break;
        }
        if (!((n) & (1 << (i))) && ((sol) & (1 << (i)))) {
          sol -= 1 << i;
        }
      }
    }
    cout << (sol ^ n) << "\n";
  }
}

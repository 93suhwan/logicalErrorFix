#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int tab[n];
    for (int i = 0; i < n; i++) {
      cin >> tab[i];
    }
    long long x = 1;
    tab[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (tab[i] == 1 && tab[i + 1] == 1) {
        x += 5;
        continue;
      } else if (tab[i] == 0 && tab[i + 1] == 0) {
        x = -1;
        break;
      } else if (tab[i] == 1) {
        x += 1;
      } else {
        continue;
      }
    }
    if (n == 1 && tab[0] == 0) {
      cout << 1 << endl;
    } else if (n == 1 && tab[0] == 1) {
      cout << 2 << endl;
    } else {
      cout << x << endl;
    }
  }
  return 0;
}

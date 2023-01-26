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
    for (int i = 0; i < n - 1; i++) {
      if (tab[i] == 1 && tab[i + 1] == 1) {
        x += 6;
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
    if (tab[n - 1] == 1 && tab[n - 2] != 1 && x != -1) {
      x += 1;
    }
    cout << x << endl;
  }
  return 0;
}

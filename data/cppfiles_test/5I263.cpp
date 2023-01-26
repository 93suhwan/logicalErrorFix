#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, c = 0;
    char e[200000], g[200000];
    cin >> n;
    cin >> e;
    cin >> g;
    for (int i = 0; i < n; i++) {
      if (g[i] == '1' && e[i] == '0' || g[i] == '1' && e[i - 1] == '1' ||
          g[i] == '1' && e[i + 1] == '1')
        c++;
    }
    cout << c << "\n";
  }
}

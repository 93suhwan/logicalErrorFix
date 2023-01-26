#include <bits/stdc++.h>
using namespace std;
int b[120], c[120];
int main() {
  ios ::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> b[i];
      if (i > 1) b[i] = b[i - 1] & b[i];
    }
    cout << b[n] << "\n";
  }
}

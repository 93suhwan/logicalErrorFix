#include <bits/stdc++.h>
using namespace std;
int b[120], c[120];
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> b[i];
    }
    int mak = 2e9;
    for (int l = 1; l < n; ++l) {
      int mas = 0;
      for (int r = n; r > l; r--) {
        for (int i = 0; i <= r - l; ++i) {
          c[i] = (b[l + i] & b[r - i]);
          mas = max(mas, c[i]);
        }
      }
      mak = min(mak, mas);
    }
    cout << mak << "\n";
  }
}

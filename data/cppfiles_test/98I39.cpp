#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, M;
  cin >> t;
  while (t--) {
    cin >> n;
    int ar[n + 1];
    M = 1;
    for (int i = 1; i <= n; i++, M++) {
      cin >> ar[i];
      if (ar[i] > M) {
        M = ar[i];
      }
    }
    cout << (M - n - 1) << endl;
  }
  return 0;
}

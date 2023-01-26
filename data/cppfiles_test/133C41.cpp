#include <bits/stdc++.h>
using namespace std;
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  }
  long long i, j, k, n, m, c, t, x, y;
  cin >> t;
  while (t--) {
    cin >> n;
    char ch1[n], ch2[n];
    for (i = 0; i < n - 2; i++) {
      cin >> ch1[i] >> ch2[i];
    }
    cout << ch1[0] << ch2[0];
    bool flag = 0;
    for (i = 1; i < n - 2; i++) {
      if (ch2[i - 1] != ch1[i]) {
        flag = 1;
        cout << ch1[i];
      }
      cout << ch2[i];
    }
    if (!flag) cout << ch2[n - 3];
    cout << "\n";
  }
}

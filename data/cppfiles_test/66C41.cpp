#include <bits/stdc++.h>
using namespace std;
int main() {
  int res[1000];
  int n = 1;
  for (int i = 0; i < 1000; i++) {
    if (n % 3 != 0 && n % 10 != 3) {
      res[i] = n;
      n++;
    } else {
      i--;
      n++;
    }
  }
  int t, k;
  cin >> t;
  while (t--) {
    cin >> k;
    cout << res[k - 1] << endl;
  }
  return 0;
}

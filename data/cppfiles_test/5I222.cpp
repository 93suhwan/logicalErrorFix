#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string p, e;
    cin >> e >> p;
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (p[i] - '0' == 0) {
        continue;
      }
      if (e[i] - '0' == 0) {
        c++;
      } else if (i > 0 && e[i - 1] - '0' == 1) {
        c++;
      } else if (i < n - 1 && e[i + 1] - '0' == 1) {
        c++;
      }
    }
    cout << c << endl;
  }
  return 0;
}

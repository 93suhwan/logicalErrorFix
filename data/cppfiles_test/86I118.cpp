#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string p, q;
    cin >> p >> q;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if ((p[i] == '1' && q[i] == '0') || (p[i] == '0' && q[i] == '1')) {
        sum += 2;
        continue;
      }
      if ((p[i] == '0' && q[i] == '0')) {
        if (i - 1 >= 0) {
          if (p[i - 1] == '1' && q[i - 1] == '1') {
            sum += 2;
            continue;
          }
        }
        if (i + 1 < n) {
          if (p[i + 1] == '1' && q[i + 1] == '1') {
            sum += 2;
            i++;
            p[i + 1] = '0';
            q[i + 1] = '0';
            continue;
          }
        }
        sum++;
      }
    }
    cout << sum << endl;
  }
}

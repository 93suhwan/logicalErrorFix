#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  for (int j = 0; j < T; j++) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "1 1" << endl;
      break;
    }
    if (n == 2) {
      cout << "1 2" << endl;
    }
    if (n == 3) {
      cout << "2 2" << endl;
    }
    if (n > 3 && sqrt(n) * sqrt(n) == n) {
      cout << 1 << " " << sqrt(n) << endl;
    }
    int a = (int)sqrt(n);
    int si = a + 1;
    int sj = 0;
    int sn = pow(a, 2) + 1;
    for (int i = sn; i < sn + si; i++) {
      if (i == n) {
        cout << sj + 1 << " " << si << endl;
        break;
      }
      sj += 1;
    }
    int nsi = si;
    for (int i = sn + si; i < sn + si + a; i++) {
      if (i == n) {
        cout << sj << " " << nsi - 1 << endl;
        break;
      }
      nsi -= 1;
    }
  }
}

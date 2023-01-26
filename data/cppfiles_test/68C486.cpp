#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  for (int j = 0; j < T; j++) {
    int n;
    cin >> n;
    if ((int)sqrt(n) * (int)sqrt(n) == n) {
      cout << sqrt(n) << " " << 1 << endl;
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

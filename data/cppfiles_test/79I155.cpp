#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    string n;
    int k;
    cin >> k >> n;
    vector<int> v(k);
    long long i, c, l, p;
    for (i = k - 1; i >= 0; i--) {
      v[i] = n[i] - '0';
    }
    for (i = 0; i < k; i++) {
      if ((v[i] % 2 == 0 && v[i] != 2) || v[i] == 9) {
        cout << 1 << endl;
        cout << v[i] << endl;
        break;
      }
      if (v[i] == 1) {
        cout << 1 << endl;
        cout << v[i] << endl;
        break;
      } else {
        for (l = i + 1; l < k; l++) {
          c = v[i] * 10 + v[l];
          if (c % 2 == 0 || c % 3 == 0 || c % 5 == 0 || c % 7 == 0) {
            cout << 2 << endl;
            cout << c << endl;
            break;
          }
        }
      }
      break;
    }
  }
  return 0;
}

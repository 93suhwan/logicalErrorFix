#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
int main() {
  int Tc, n, EN, i;
  cin >> Tc;
  while (Tc--) {
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    EN = n - (n & 1) - 2;
    for (i = 0; i < EN; i += 2) {
      b[i] = -a[i + 1];
      b[i + 1] = a[i];
    }
    if (n & 1) {
      if (a[EN] + a[EN + 1] == 0) {
        if (a[EN + 1] + a[EN + 2] == 0) {
          b[EN + 1] = a[EN + 2] + a[EN];
          b[EN] = b[EN + 2] = -a[EN + 1];
        } else {
          b[EN] = a[EN + 1] + a[EN + 2];
          b[EN + 1] = b[EN + 2] = -a[EN];
        }
      } else {
        b[EN + 2] = a[EN] + a[EN + 1];
        b[EN] = b[EN + 1] = -a[EN + 2];
      }
    } else {
      b[EN] = a[EN + 1];
      b[EN + 1] = -a[EN];
    }
    for (i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;
  }
}

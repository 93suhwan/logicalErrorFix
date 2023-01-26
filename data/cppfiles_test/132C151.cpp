#include <bits/stdc++.h>
using namespace std;
int main() {
  long t;
  cin >> t;
  while (t--) {
    long long b[7];
    for (int i = 0; i < 7; i++) {
      cin >> b[i];
    }
    int m = 0, n = 0, o = 0;
    int i = 0, j = 1, k = 2;
    for (i; i < 7; i++) {
      for (j; j < 7; j++) {
        for (k; k < 7; k++) {
          if ((b[i] + b[j] + b[k] == b[6])) {
            m = i;
            n = j;
            o = k;
          }
        }
      }
    }
    cout << b[m] << " " << b[n] << " " << b[o] << endl;
  }
  return 0;
}

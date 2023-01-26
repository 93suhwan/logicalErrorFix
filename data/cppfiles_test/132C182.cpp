#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[8], t;
  long long c;
  cin >> t;
  while (t--) {
    bool f = 1;
    for (int i = 0; i < 7; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 7; j++) {
        for (int k = 0; k < 7; k++) {
          if ((a[i] + a[j] + a[k]) == a[6] && i != j && i != k) {
            cout << a[i] << " " << a[j] << " " << a[k] << endl;
            f = 0;
            break;
          }
        }
        if (f == 0) break;
      }
      if (f == 0) break;
    }
  }
}

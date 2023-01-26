#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, counter = 0;
  bool answer = false;
  cin >> t;
  long long a[7], b[4];
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < 7; j++) {
      cin >> a[j];
    }
    for (int a1 = 0; a1 < 5; a1++) {
      for (int a2 = a1 + 1; a2 < 6; a2++) {
        for (int a3 = a2 + 1; a3 < 5; a3++) {
          b[0] = a[a1] + a[a2];
          b[1] = a[a1] + a[a3];
          b[2] = a[a2] + a[a3];
          b[3] = a[a1] + a[a2] + a[a3];
          for (int j = 0; j < 7; j++) {
            if (j != a3 and j != a2 and j != a1) {
              if (a[j] == b[0]) {
                counter++;
                b[0] = -10000;
              } else if (a[j] == b[1]) {
                counter++;
                b[1] = -10000;
              } else if (a[j] == b[2]) {
                counter++;
                b[2] = -10000;
              } else if (a[j] == b[3]) {
                counter++;
                b[3] = -10000;
              }
              if (counter == 4) {
                cout << a[a1] << " " << a[a2] << " " << a[a3] << endl;
                answer = true;
                break;
              }
            }
          }
          counter = 0;
          if (answer) break;
        }
        if (answer) break;
      }
      if (answer) break;
    }
    answer = false;
  }
  return 0;
}

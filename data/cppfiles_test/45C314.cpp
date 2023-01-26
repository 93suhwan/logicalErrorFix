#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ar[n];
    int h = 1;
    bool c = false;
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
    }
    if (ar[0] == 1) h++;
    for (int i = 1; i < n; i++) {
      if (ar[i] == 0) {
        if (ar[i - 1] == 0) {
          c = true;
        }
      } else {
        if (ar[i - 1] == 1 && ar[i] == 1)
          h += 5;
        else
          h++;
      }
    }
    if (c == true) {
      cout << -1 << endl;
    } else {
      cout << h << endl;
    }
  }
}

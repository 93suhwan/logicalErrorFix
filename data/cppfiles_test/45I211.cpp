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
    for (int i = 0; i < n - 1; i++) {
      if (ar[i] == 0 && ar[i + 1] == 0)
        c = true;
      else {
        if (ar[i] == 1 && ar[i + 1] == 1)
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

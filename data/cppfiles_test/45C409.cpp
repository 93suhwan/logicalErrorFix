#include <bits/stdc++.h>
using namespace std;
void io() {}
int main() {
  io();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int k = 1;
    if (a[0] == 1) k += 1;
    for (int i = 1; i < n; i++) {
      if (a[i] == 1 && a[i - 1] == 1) {
        k += 5;
      } else if (a[i] == 1) {
        k += 1;
      } else if (a[i] == 0 && a[i - 1] == 0) {
        k = -1;
        break;
      }
    }
    cout << k << endl;
  }
}

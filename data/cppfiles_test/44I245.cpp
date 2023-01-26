#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, js = 0, os = 0;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] % 2)
      js++;
    else
      os++;
  }
  if (js == 1) {
    for (int i = 1; i <= n; i++) {
      if (a[i] % 2) {
        cout << i << endl;
        break;
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {
      if (a[i] % 2 == 0) {
        cout << i << endl;
        break;
      }
    }
  }
}

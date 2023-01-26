#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, t, n, e;
  string s;
  cin >> t;
  for (int k = 0; k < t; k++) {
    cin >> n;
    e = 0;
    i = 1;
    while (i * i <= n) {
      e++;
      i++;
    }
    i = 1;
    while (i * i * i <= n) {
      e++;
      i++;
    }
    i = 1;
    while (i * i * i * i * i * i <= n) {
      e--;
      i++;
    }
    cout << e << "\n";
  }
  return 0;
}

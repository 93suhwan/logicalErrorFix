#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  for (int q = 1; q <= t; q++) {
    int n, i, j;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ok = 0;
    for (i = 1; i < n; i++) {
      if (a[i] < a[i - 1]) {
        ok = 1;
        break;
      }
    }
    if (ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

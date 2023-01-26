#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int a1 = 0, a0 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) a1++;
      if (a[i] == 0) a0++;
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
      s += a[i];
    }
    cout << (a1 * pow(2, a0));
    cout << endl;
  }
  return 0;
}

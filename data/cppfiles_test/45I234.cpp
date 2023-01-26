#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    int sum = 1;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      if (a[i] == 1) {
        sum += 1;
        if (a[i + 1] == 1 && n > 1) sum += 4;
      }
      if (a[i] == 0) {
        sum += 0;
        if (a[i + 1] == 0 && n > 1) {
          cout << "-1" << endl;
          return 0;
        }
      }
    }
    cout << sum << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    int m = max(l3, max(l1, l2));
    int sum = l1 + l2 + l3;
    if (m == sum / 2) {
      cout << "YES" << endl;
    } else {
      int min1 = min(l1, min(l2, l3));
      int min2 = sum - m - min1;
      if (min1 == min2) {
        if (m % 2 == 0) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      } else {
        cout << "NO" << endl;
      }
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int a[7];
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < 7; j++) {
      cin >> a[j];
    }
    sort(a, a + 7);
    cout << a[0] << " " << a[1] << " " << a[6] - a[0] - a[1] << endl;
  }
  return 0;
}

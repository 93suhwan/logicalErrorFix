#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    int b[7];
    int a[3];
    for (int i = 0; i < 7; i++) {
      cin >> b[i];
    }
    cout << b[0] << ' ' << b[1] << ' ' << b[6] - b[0] - b[1] << endl;
  }
}

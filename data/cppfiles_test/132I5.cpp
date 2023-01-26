#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, c, arr[7];
  cin >> t;
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < 7; j++) {
      cin >> arr[j];
    }
    a = arr[0];
    b = arr[1];
    c = arr[5] - b;
    cout << a << " " << b << " " << c;
  }
  return 0;
}

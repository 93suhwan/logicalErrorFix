#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int b[7];
    for (int j = 0; j < 7; j++) cin >> b[j];
    int a[3];
    a[0] = b[0];
    int k = 1;
    a[1] = b[1];
    a[2] = b[6] - a[0] - a[1];
    while (b[0] == b[k]) k++;
    a[1] = b[k];
    for (int j = 0; j < 3; j++) cout << " " << a[j];
    cout << endl;
  }
  return 0;
}

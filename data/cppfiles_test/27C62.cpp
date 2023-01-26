#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  long long int** a = new long long int*[t];
  for (int i = 0; i < t; i++) {
    a[i] = new long long int[3];
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    if (a[i][2] == 0 || a[i][2] == 1) {
      cout << "NO" << endl;
    } else if (a[i][2] == 2) {
      if (a[i][0] == 1 && a[i][1] == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else if (a[i][2] == 3) {
      if (a[i][1] == a[i][0] * (a[i][0] - 1) / 2) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      if (a[i][0] - 1 > a[i][1]) {
        cout << "NO" << endl;
      } else if (a[i][1] > a[i][0] * (a[i][0] - 1) / 2) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
}

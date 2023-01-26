#include <bits/stdc++.h>
using namespace std;
int NumOfOperation(unsigned long long int c, unsigned long long int d) {
  unsigned long long int temp;
  if (c - d == 1 || d - c == 1) {
    return -1;
  } else if ((c == 0 && d % 2 != 0) || (d == 0 && c % 2 != 0)) {
    return -1;
  } else if (((c - d) % 2 != 0) || ((d - c) % 2 != 0)) {
    return -1;
  } else if (c == d && c != 0 && d != 0) {
    return 1;
  } else if (c == 0 && d == 0) {
    return 0;
  } else {
    return 2;
  }
}
int main() {
  int t;
  cin >> t;
  unsigned long long int arr[t][2];
  for (int i = 0; i < t; i++) {
    cin >> arr[i][0] >> arr[i][1];
  }
  for (int i = 0; i < t; i++) {
    cout << NumOfOperation(arr[i][0], arr[i][1]) << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    int B[7];
    for (int i = 0; i < 7; i++) {
      cin >> B[i];
    }
    int A[3];
    A[0] = B[0];
    A[1] = B[1];
    if (((B[0] + B[1]) < B[3]) && ((B[1] + B[2]) < B[3]) &&
        ((B[0] + B[3]) < B[3])) {
      A[2] = B[3];
    } else {
      A[2] = B[2];
    }
    for (int i = 0; i < 3; i++) {
      cout << A[i] << endl;
    }
  }
  return 0;
}

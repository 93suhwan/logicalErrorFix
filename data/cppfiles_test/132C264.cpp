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
    int sum = B[0] + B[1];
    for (int i = 0; i < 7; i++) {
      if ((sum + B[i]) == B[6]) {
        A[2] = B[i];
      }
    }
    for (int i = 0; i < 3; i++) {
      cout << A[i] << " ";
    }
    cout << endl;
  }
  return 0;
}

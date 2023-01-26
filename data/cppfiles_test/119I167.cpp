#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> t;
  while (t > 0) {
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
      sort(A, A + n);
      if (A[n - 1] - A[0] != 0 && A[n - 1] - A[0] != 1) {
        A[n - 1]--;
        A[0]++;
        ;
      }
    }
    cout << A[n - 1] - A[0] << endl;
    t--;
  }
  return 0;
}

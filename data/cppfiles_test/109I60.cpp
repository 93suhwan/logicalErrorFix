#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, count = 0;
    cin >> n;
    int a;
    int A[n];
    cin >> a;
    for (int i = 0; i < n; i++) A[i] = 0;
    i = n - 1;
    while (a) {
      A[i] = a % 10;
      a /= 10;
      i--;
    }
    count = count + A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (A[i] != 0) count = count + 1 + A[i];
    }
    cout << count << "\n";
  }
  return 0;
}

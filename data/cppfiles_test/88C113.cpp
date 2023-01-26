#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long A[n];
    for (int i = 0; i < n; ++i) {
      cin >> A[i];
    }
    if (n % 2 == 0) {
      cout << "YES\n";
    } else {
      int f = 0;
      for (int i = 1; i < n; ++i) {
        if (A[i] <= A[i - 1]) {
          f = 1;
          break;
        }
      }
      if (f)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}

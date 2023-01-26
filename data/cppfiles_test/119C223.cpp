#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n;
    cin >> n;
    long long int A[n];
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
      sum = sum + A[i];
    }
    if (sum % n == 0) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
    t--;
  }
  return 0;
}

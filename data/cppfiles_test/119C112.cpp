#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int A[n];
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
      sum += A[i];
    }
    double mean = ((double)sum) / n;
    if (ceil(mean) == mean) {
      cout << "0\n";
    } else {
      cout << "1\n";
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, count = 0, no = 0;
    cin >> n;
    long long int a;
    long long int A[n];
    char num[n];
    for (long long int i = 0; i < n; i++) cin >> num[i];
    for (long long int i = 0; i < n; i++) {
      A[i] = num[i] - '0';
    }
    i = n - 1;
    while (a) {
      A[i] = a % 10;
      a /= 10;
      i--;
      no++;
    }
    count = count + A[n - 1];
    for (long long int i = n - 2; i >= 0; i--) {
      if (A[i] > 0) {
        count = count + 1 + A[i];
      }
    }
    cout << count << "\n";
  }
  return 0;
}

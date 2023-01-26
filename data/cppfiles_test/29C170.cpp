#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    long long ones = 0, zeros = 0;
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] == 1) {
        ones++;
      } else if (arr[i] == 0) {
        zeros++;
      }
    }
    long long ans = ones * pow(2, zeros);
    cout << ans << "\n";
  }
  return 0;
}

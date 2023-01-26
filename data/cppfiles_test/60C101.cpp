#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    long long k = arr[0];
    for (int i = 1; i < n; i++) {
      k &= arr[i];
    }
    cout << k << endl;
  }
  return 0;
}

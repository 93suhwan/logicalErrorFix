#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long start = 2;
    long long arr[n];
    long long k = 0;
    for (long long i = 0; i < n; i++) {
      arr[k++] = start;
      start++;
    }
    for (auto it : arr) cout << it << " ";
    cout << endl;
  }
  return 0;
}

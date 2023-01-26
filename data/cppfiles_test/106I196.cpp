#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string arr[n];
    long long k = 0;
    string res = "11";
    long long div = n / 7;
    long long rem = n % 7;
    for (long long i = 0; i < div; i++) {
      res = "11";
      for (long long j = 0; j < 7; j++) {
        arr[k++] = res;
        res += '1';
      }
    }
    res = "11";
    for (long long i = 0; i < rem; i++) {
      arr[k++] = res;
      res += '1';
    }
    for (auto it : arr) cout << it << " ";
    cout << endl;
  }
  return 0;
}

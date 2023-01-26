#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int hours = 0;
    long long int curr = 1;
    long long int total = 1;
    while (total < n) {
      if (k >= curr) {
        total += curr;
        curr = 2LL * curr;
        hours += 1;
      } else {
        break;
      }
    }
    if (total >= n) {
      cout << hours << endl;
    } else {
      long long int left = n - total;
      if (left % k) {
        cout << left / k + 1 + hours << endl;
      } else {
        cout << left / k + hours << endl;
      }
    }
  }
}

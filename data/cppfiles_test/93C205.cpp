#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k, hours = 0;
    cin >> n >> k;
    long long active = 1;
    n--;
    while (n > 0) {
      if (active < k) {
        n = n - active;
        hours++;
        active *= 2;
      } else {
        long long q = n / k;
        hours += q;
        if (n - q * k) {
          hours++;
        }
        break;
      }
    }
    cout << hours << endl;
  }
}

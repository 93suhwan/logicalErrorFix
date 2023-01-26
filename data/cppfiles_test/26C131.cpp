#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long res = 1;
    long long k = n * 2;
    while (k != 2) {
      res = (res * k) % 1000000007;
      k--;
    }
    cout << res << endl;
  }
}

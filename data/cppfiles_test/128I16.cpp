#include <bits/stdc++.h>
using namespace std;
long long t, n;
vector<long long> v;
long long lowerPrime(int x) {
  for (int i = x; i >= 2; i--) {
    bool prime = true;
    for (int j = 2; j <= sqrt(i); j++) {
      if (i % j == 0) {
        prime = false;
      }
    }
    if (prime) return i;
  }
}
int main() {
  cin >> t;
  while (t--) {
    int a = 0, b = 0, c = 0;
    cin >> n;
    if (n % 2 == 0) {
      a = n / 2;
      b = n / 2 - 1;
      c = 1;
    } else {
      a = lowerPrime(n - 1);
      b = n - a - 1;
      c = 1;
    }
    cout << a << " " << b << " " << c << endl;
  }
}

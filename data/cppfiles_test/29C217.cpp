#include <bits/stdc++.h>
using namespace std;
long long int pow(long long int a, long long int n) {
  long long int val = 1;
  while (n) {
    if (n & 1 == 1) {
      val *= a;
    }
    a *= a;
    n >>= 1;
  }
  return val;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int s0 = 0, s1 = 0;
    long long int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0) s0++;
      if (a[i] == 1) s1++;
    }
    cout << (pow(2, s0) * s1) << endl;
  }
  return 0;
}

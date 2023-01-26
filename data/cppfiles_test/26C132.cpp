#include <bits/stdc++.h>
using namespace std;
int solv();
long long int fac(long long int n);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int testcases = 1;
  cin >> testcases;
  while (testcases--) solv();
}
int solv() {
  long long int n, m;
  cin >> n;
  m = 2 * n;
  if (m == 2) {
    cout << 1 << endl;
    return 0;
  }
  cout << fac(m) << endl;
  return 0;
}
long long int fac(long long int n) {
  long long int k = 1000000007;
  long long int m = n;
  while (n > 3) {
    m = ((m % k) * (n - 1) % k) % k;
    n--;
  }
  return m;
}

#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
void cyclicShift(long long int start, long long int end, long long int a[]) {
  long long int i, temp = a[start];
  for (i = start; i < (end - start); i++) a[i] = a[i + 1];
  a[i] = temp;
}
int main() {
  long long int t, i, n, sum, x, rem, init;
  cin >> t;
  while (t--) {
    cin >> x >> n;
    rem = n / 4;
    init = rem * 4;
    for (i = init + 1; i <= n; i++) {
      if (x % 2 == 0)
        x -= i;
      else
        x += i;
    }
    cout << x;
    cout << endl;
  }
  return 0;
}

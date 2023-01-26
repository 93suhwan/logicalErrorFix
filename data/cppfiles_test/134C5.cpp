#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
int main() {
  int t, n;
  long long A[105], odd, even;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    odd = A[1];
    even = A[2];
    for (int i = 3; i <= n; i += 2) odd = gcd(odd, A[i]);
    for (int i = 4; i <= n; i += 2) even = gcd(even, A[i]);
    for (int i = 2; i <= n; i += 2)
      if (A[i] % odd == 0) odd = 1;
    for (int i = 1; i <= n; i += 2)
      if (A[i] % even == 0) even = 1;
    if (max(odd, even) == 1)
      cout << 0 << endl;
    else
      cout << max(odd, even) << endl;
  }
}

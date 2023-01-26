#include <bits/stdc++.h>
using namespace std;
long long power(long long b, long long exp) {
  if (exp == 0) return 1;
  long long temp = power(b, exp / 2);
  temp = (temp * temp) % 1000000007;
  if (exp & 1) temp = (temp * b) % 1000000007;
  return temp % 1000000007;
}
void solver() {
  long long n, k;
  cin >> n >> k;
  std::vector<long long> A(n);
  for (long long i = 0; i < n; i++) cin >> A[i], A[i] = power(10, A[i]);
  long long i = 0, a = 9;
  long long ans = 0;
  long long x;
  long long Mn = 0, abc = 0;
  while (k > 0) {
    if (i < n - 1) {
      Mn = A[i + 1] - 1 - abc;
      abc += Mn;
      long long req = (Mn) / A[i];
      if (k > req)
        k -= req, ans += Mn;
      else
        ans += k * A[i], k = 0;
      i++;
    } else {
      ans += k * A[i];
      k = 0;
    }
  }
  i = 0;
  bool p = 1;
  while (p and i < n - 1) {
    if ((ans / A[i]) % 10 != 9) ans += A[i], p = 0;
    i++;
  }
  if (p) ans += A[n - 1];
  cout << ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solver();
    cout << '\n';
  }
  return 0;
}

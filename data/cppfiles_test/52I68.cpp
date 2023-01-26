#include <bits/stdc++.h>
using namespace std;
long long factorial(long long n) {
  if (n == 0 || n == 1) return 1;
  return n * factorial(n - 1);
}
long long combination(long long n, long long r) {
  return factorial(n) / (factorial(n - r) * factorial(r));
}
long long permutation(long long n, long long r) {
  return combination(n, r) * factorial(r);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    float a[n];
    float sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a, a + n);
    sum -= a[n - 1];
    float res = sum / (n - 1) + a[n - 1];
    setprecision(20);
    cout << setprecision(20) << res << "\n";
  }
  return 0;
}
